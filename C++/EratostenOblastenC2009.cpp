#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char argv[])
{
ios_base::sync_with_stdio(false);
int countMet=0;
int n;
cin>>n;
bool prime[3000][3];
memset(prime,true,sizeof(prime));
    for (long long int p = 2; p * p <= n; p++)
    {
        if (prime[p][0] == true)
         {
            for (long long int i = p * p; i <= n; i += p)
            {
                int col=n/i;
                int row=n%i;
                prime[row][col] = false;
            }
        }
    }
    for (int p = 2; p <= n; p++)
    {
        int col=n/p;
        int row=n%p;
        if (prime[row][col])
            cout << p << " ";
    }
}


