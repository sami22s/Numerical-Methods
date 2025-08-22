#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double f(double x)
{
    return x-exp(-x);
}

int main()
{
    double a,b,c,tol;
    int max;

    cout<<"enter the first guess : ";
    cin>>a;
    cout<<"enter the second guess : ";
    cin>>b;
    cout<<"enter the tolerance : ";
    cin>>tol;
    cout<<"enter the number of steps : ";
    cin>>max;

    cout<<"\nSteps\t\ta\t\tf(a)\t\tb\t\tf(b)\t\tc\t\tf(c)\n";
    cout<<"---------------------------------------------------------------------------------------------------------------------------";
    cout<<fixed<<setprecision(6);

    for(int i=1;i<=max;i++)
    {
        if(f(b)-f(a)==0)
        {
            cout<<"Math Error";
            return 0;
        }

        c=(a*f(b)-b*f(a))/(f(b)-f(a));

        cout<<"\n"<<i<<"\t\t"<<a<<"\t"<<f(a)<<"\t"<<b<<"\t"<<f(b)<<"\t"<<c<<"\t"<<f(c)<<"\n";

        if(fabs(f(c))<tol)
        {
            cout<<"\nThe Root is : "<<c;
            return 0;
        }

        a=b;
        b=c;

    }

    cout<<"The root is not found in the given steps ";

    return 0;

}