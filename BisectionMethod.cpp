#include<bits/stdc++.h>

using namespace std;
//function x2 - 4x -10
double f(double x)
{
    return x * x  - 4 * x - 10;
}
// Bisection method
double bisection(double x1, double x2, double E)
{
    double f1 = f(x1);
    double f2 = f(x2);
    if (f1 * f2 > 0)
    {
        cout << "Initial values do not bracket the root." << endl;
        return NAN;
    }

    double x0, f0;

    do
    {
        x0 = (x1 + x2) / 2;
        f0 = f(x0);

        if (f1 * f0 < 0)
        {
            x2 = x0;
        }
        else
        {
            x1 = x0;
            f1 = f0;
        }
    }
    while (fabs(x2 - x1) / x2 >= E);

    return (x1 + x2) / 2;
}

int main()
{

    double x1,x2;
    cout<<"Enter left end point : ";
    cin>>x1;//-1
    cout<<"Enter left end point : ";
    cin>>x2;//-2
    double E = 0.0001;
    double root = bisection(x1, x2, E);

    if (!isnan(root))
    {
        cout << "Approximate root: " << root << endl;
    }

    return 0;
}
