#include<bits/stdc++.h>
using namespace std;

// given equation : x^3 – x^2 + 2.

double fnc_value(double x)
{
    //return (x*x*x) - (x*x) + 2;
    //return (x*x*x) - (0.165*x*x) + 3.993e-4;
    //return (x*x*x) - (4*x*x) -x + 4;
    return (2*x*x*x) - (2.5*x) - 5;
}

double falsePositionMethod(double lower, double upper, double thresold)
{
    double x_mid, temp1, temp2, fnc_midValue, prev_x_Mid=0, ans, error = 100;

    int step = 0;

    ofstream resultFile;

    resultFile.open("FinalOutput.csv");

    while(error>thresold)
    {
        step++;

        temp1 = fnc_value(upper)*(upper - lower);

        temp2 = fnc_value(upper) - fnc_value(lower);

        x_mid = -(temp1/temp2) + upper;

        error = abs(((prev_x_Mid - x_mid)/x_mid)*100);

        prev_x_Mid = x_mid;

        fnc_midValue = fnc_value(x_mid);

        if(fnc_midValue>0) upper = x_mid;

        else if(fnc_midValue==0)
        {
            ans = x_mid;
            break;
        }

        else lower = x_mid;

        ans = x_mid;

        resultFile<<step<<","<<lower<<","<<upper<<","<<x_mid<<","<<fnc_midValue<<",\n";
    }

    resultFile.close();

    return ans;
}

main()
{
    double lower, upper, thresold;

    ifstream ifs;

    ifs.open("input");

    ifs>>lower>>upper>>thresold;

    //double ans = falsePositionMethod(0, .11, 1);

    double ans = falsePositionMethod(lower, upper, thresold);

    cout<<ans<<endl;
}
