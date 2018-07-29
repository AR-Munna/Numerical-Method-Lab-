#include<bits/stdc++.h>
using namespace std;

void calculate_function_value(double lower, double upper)
{
    double x = lower;

    while(x<=upper)
    {
        double result = exp(x) - 5*x*x;
        cout<<"x: "<<x<<" --------------------------- "<<"f(x): "<<result<<endl;
        x += 0.1;
    }
}

double fnc_value(double x)
{
    //return (x*x*x) - (x*x) + 2;
    return (x*x*x) - (4*x*x) -x + 4;
    //return (x*x*x) - 5 + (3*x);

}

double bisection_method(double lower, double upper, double thresold)
{
    double x_mid, function_value, ans, f_lower=0, f_upper=0, error=100, prev_x_Mid=0;

    ofstream resultFile;

    resultFile.open("FinalOutputBisectionMethod.csv");

    int step = 0;

    while(error>thresold)
    {
        step++;

        x_mid = (lower + upper)/2.0;

        error = abs(((prev_x_Mid - x_mid)/x_mid)*100);

        prev_x_Mid = x_mid;

        function_value =  fnc_value(x_mid);

        f_lower = fnc_value(lower);

        f_upper = fnc_value(upper);

        //if(f_lower*f_upper<0) break;

        if(function_value>0) upper = x_mid;

        else lower = x_mid;

        ans = x_mid;

        resultFile<<step<<","<<lower<<","<<upper<<","<<x_mid<<","<<function_value<<","<<error<<",\n";
    }

    resultFile.close();

    return ans;
}

main()
{
    double lower, upper, thresold;

    ifstream ifs;

    ifs.open("inputBisectionMethod");

    ifs>>lower>>upper>>thresold;

    double ans = bisection_method(lower, upper, thresold);

    cout<<ans<<endl;
}
