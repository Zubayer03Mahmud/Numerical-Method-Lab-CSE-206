#include<bits/stdc++.h>
#define max_iter 100000
using namespace std;

double f(double x)
{
    return x*x*x - x*x + 2;
}

void falsemethod(double a, double b)

{
    if(f(a) * f(b) >= 0)
    {
        cout<<"You have not assume right a and b :" <<endl;
        return;
    }

    double c = a;
    for(int i=0; i<max_iter; i++)
    {
        c = (a*f(b) - b*f(a))/ (f(b) - f(a));
        if(f(c)==0)
            break;
        else if(f(c)*f(a)< 0)
            b=c;
        else
            a=c;
    }
    cout<<"The value of the root is : "<< c;


}
int main()
{
    double a,b;
    //-100,422
    cout<<"Enter left end point : ";
    cin>>a;
    cout<<"Enter right end point : ";
    cin>>b;
    falsemethod(a,b);
    return 0;
}
