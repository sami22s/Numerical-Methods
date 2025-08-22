#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of variables: ";
    cin >> n;

    double a[n][n+1], x[n];

    cout << "Enter the augmented matrix:\n";
    for(int i=0; i<n; i++)
        for(int j=0; j<=n; j++)
            cin >> a[i][j];

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            double ratio = a[j][i] / a[i][i];
            for(int k=0; k<=n; k++)
                a[j][k] -= ratio * a[i][k];
        }
    }

    x[n-1] = a[n-1][n] / a[n-1][n-1];
    for(int i=n-2; i>=0; i--)
    {
        x[i] = a[i][n];
        for(int j=i+1; j<n; j++)
            x[i] -= a[i][j]*x[j];
        x[i] /= a[i][i];
    }

    cout << "\nSolution:\n";
    for(int i=0; i<n; i++)
        cout << "x" << i+1 << " = " << fixed << setprecision(6) << x[i] << endl;

    return 0;
}