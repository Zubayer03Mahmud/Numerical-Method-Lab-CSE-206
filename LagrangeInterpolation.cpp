#include<bits/stdc++.h>
using namespace std;
float u_cal(float u, int n)
{
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u - i);
    return temp;
}
int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

int main()
{
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    float x[n], y[n][n];
    cout << "Enter the x values:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i << "] = ";
        cin >> x[i];
    }
    cout << "Enter the y values corresponding to the x values:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "y[" << i << "] = ";
        cin >> y[i][0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
    }
    //  cout << "\nForward Difference Table:\n";
    for (int i = 0; i < n; i++)
    {
        cout << setw(10) << x[i] << "\t";
        for (int j = 0; j < n - i; j++)
            cout << setw(10) << y[i][j] << "\t";
        cout << endl;
    }
    float value;
    cout << "\nEnter the value to interpolate at: ";
    cin >> value;
    float sum = y[0][0];
    float u = (value - x[0]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++)
    {
        sum = sum + (u_cal(u, i) * y[0][i]) / fact(i);
    }

    cout << "\nValue at " << value << " is " << sum << endl;
    return 0;
}
