#include<bits/stdc++.h>
using namespace std;

void leastSquaresRegression(const vector<double>& x, const vector<double>& y, double& b, double& a)
{
    if (x.size() != y.size() || x.empty())
    {
        cout << "Input vectors must be of the same size and not empty." << endl;
        return;
    }

    size_t n = x.size();


    double sum_x = 0.0;
    double sum_y = 0.0;
    double sum_xx = 0.0;
    double sum_xy = 0.0;

    for (size_t i = 0; i < n; ++i)
    {
        sum_x += x[i];
        sum_y += y[i];
        sum_xx += x[i] * x[i];
        sum_xy += x[i] * y[i];
    }


    double denominator = n * sum_xx - sum_x * sum_x;
    if (denominator == 0)
    {
        cout << "Error: The denominator in the slope calculation is zero." << endl;
        return;
    }

    b = (n * sum_xy - sum_x * sum_y) / denominator;
    a = (sum_y - b * sum_x) / n;
}

int main()
{
    size_t n;


    cout << "Enter the number of data points: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "The number of data points must be positive." << endl;
        return 1;
    }

    vector<double> x(n);
    vector<double> y(n);


    cout << "Enter the x values:\n";
    for (size_t i = 0; i < n; ++i)
    {
        cin >> x[i];
    }

    cout << "Enter the y values:\n";
    for (size_t i = 0; i < n; ++i)
    {
        cin >> y[i];
    }

    double a,b;

    leastSquaresRegression(x, y, b, a);

    cout << "The regression line is y = " << b << "x + " << a << endl;

    return 0;
}

