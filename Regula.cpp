#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double f(double x)
{
    return cos(x)-sin(x);
}

int main ()
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

    if(f(a)*f(b)>=0)
    {
        cout<<"Invalid Guess";
        return 0;
    }

    cout<<"\nSteps\t\ta\t\tf(a)\t\tb\t\tf(b)\t\tc\t\tf(c)\n";
    cout<<"---------------------------------------------------------------------------------------------------------------------------------";
    cout<<fixed<<setprecision(6);
    
    for(int i=1;i<=max;i++)
    {
        c=(a*f(b)-b*f(a))/(f(b)-f(a));

        cout<<"\n"<<i<<"\t\t"<<a<<"\t"<<f(a)<<"\t"<<b<<"\t"<<f(b)<<"\t"<<c<<"\t"<<f(c)<<"\n";

        if(fabs(f(c))<tol || (b-a)/2<tol)
        {
            cout<<"\nThe root is "<<c;
            return 0;
        }

        if(f(c)*f(b)<0)
        {
            b=c;
        }
        else
        {
            a=c;
        }
    }

    cout<<"Root is not found in the given steps ";
    return 0;
}