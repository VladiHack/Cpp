#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a;int b;
unordered_map<int,bool> primeUsed;
int primesSum=0;
void SieveOfEratosthenes()
{
    unordered_map<int,bool> prime;
    for (int p = 2; p <= b; p++)
    {
        if (prime[p] == false)
        {
            if(p>=a&&primeUsed[p]==false)
            {
                primeUsed[p]=true;
                primesSum++;
            }
            for (int i = p + p; i <= b; i += p)
            {
                prime[i]=true;
                if(i>=a&&primeUsed[p]==false)
                {
                    primeUsed[p]=true;
                    primesSum++;
                }
            }
        }
    }
}
int main()
{
    cin>>a>>b;
    SieveOfEratosthenes();
    cout<<primesSum;
}
