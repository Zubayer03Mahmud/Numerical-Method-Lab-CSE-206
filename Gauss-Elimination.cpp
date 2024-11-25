#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i,n) for(int i=0;i<n;i++)
#define test int t;cin>>t;while(t--)
using namespace std;
#define N 3
int forwardElim(double mat[N][N + 1]);
void backSub(double mat[N][N + 1]);
void gaussianElimination(double mat[N][N + 1])
{
    int singular_flag = forwardElim(mat);
    if (singular_flag != -1)
    {
        cout << "Singular Matrix." << endl;
        if (mat[singular_flag][N])
            cout << "Inconsistent System." << endl;
        else
            cout << "May have infinitely many solutions." << endl;

        return;
    }
    backSub(mat);
}
void swap_row(double mat[N][N + 1], int i, int j)
{
    for (int k = 0; k <= N; k++)
    {
        double temp = mat[i][k];
        mat[i][k] = mat[j][k];
        mat[j][k] = temp;
    }
}
void print(double mat[N][N + 1])
{
    for (int i = 0; i < N; i++, cout << endl)
        for (int j = 0; j <= N; j++)
            cout << mat[i][j] << " ";

    cout << endl;
}
int forwardElim(double mat[N][N + 1])
{
    for (int k = 0; k < N; k++)
    {
        int i_max = k;
        double v_max = abs(mat[i_max][k]);
        for (int i = k + 1; i < N; i++)
        {
            if (abs(mat[i][k]) > v_max)
            {
                v_max = abs(mat[i][k]);
                i_max = i;
            }
        }
        if (mat[i_max][k] == 0)
            return k;
        if (i_max != k)
            swap_row(mat, k, i_max);

        for (int i = k + 1; i < N; i++)
        {
            double f = mat[i][k] / mat[k][k];
            for (int j = k + 1; j <= N; j++)
                mat[i][j] -= mat[k][j] * f;
            mat[i][k] = 0;
        }
    }
    return -1;
}
void backSub(double mat[N][N + 1])
{
    double x[N];
    for (int i = N - 1; i >= 0; i--)
    {
        x[i] = mat[i][N];
        for (int j = i + 1; j < N; j++)
        {
            x[i] -= mat[i][j] * x[j];
        }
        x[i] = x[i] / mat[i][i];
    }

    cout << "\nSolution for the system:" << endl;
    for (int i = 0; i < N; i++)
        cout << x[i] << endl;
}
int main()
{
    double mat[N][N + 1];

    cout << "Enter the augmented matrix (each row in a new line, elements separated by spaces):" << endl;
    cout<<"Equation is : :\n3x1 + 6x2 + x3 = 16\n2x1 + 4x2 + 3x3 = 13\nx1 + 3x2 + 2x3 =9\n\n "<<endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            cin >> mat[i][j];
        }
    }

    gaussianElimination(mat);

    return 0;
}

