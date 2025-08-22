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

    for(int i=0; i<n; i++)
    {
        double pivot = a[i][i];
        for(int j=0; j<=n; j++)
            a[i][j] /= pivot;

        for(int j=0; j<n; j++)
        {
            if(i != j)
            {
                double factor = a[j][i];
                for(int k=0; k<=n; k++)
                    a[j][k] -= factor * a[i][k];
            }
        }
    }

    cout << "\nSolution:\n";
    for(int i=0; i<n; i++)
        cout << "x" << i+1 << " = " << fixed << setprecision(6) << a[i][n] << endl;

    return 0;
}