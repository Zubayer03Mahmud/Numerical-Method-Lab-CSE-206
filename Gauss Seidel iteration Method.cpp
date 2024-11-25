#include<bits/stdc++.h>
#define f1(x,y,z) (5-y-z)/2
#define f2(x,y,z) (15-3*x-2*z)/5
#define f3(x,y,z) (8-2*x-y)/4
using namespace std;
int main()
{
    float x0=0, y0=0, z0=0, x1, y1, z1,it;
    cout<<"Enter number of iteration: ";
    cin>>it;
    while(it--)
    {
        x1 = f1(x0,y0,z0);
        y1 = f2(x1,y0,z0);
        z1 = f3(x1,y1,z0);
        x0 = x1;
        y0 = y1;
        z0 = z1;
    }
    cout<< endl<<"Solution: x = "<<
        x1<<", y = "<< y1<<" and z = "<<
        z1<<endl;
    return 0;
}
