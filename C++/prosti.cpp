#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int constant=1000;
int arr[1000001];
void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
      {
        if (prime[p] == true)
        {
            arr[p]++;
            for (int i = p*2; i <= n; i += p)
                {prime[i] = false;
                arr[i]++;
                }
        }
    }
}
int main()
{
    memset(arr,0,sizeof(arr));
    arr[1]=1;
    SieveOfEratosthenes(constant*constant);
    while(true)
    {
        int n;int r;int c;
        cin>>n;
        if(n==0)
        {
            break;
        }
        cin>>r>>c;
        vector<int> counter[n*n];
        for(int i=1;i<=n*n;i++)
        {
            counter[arr[i]].push_back(i);
        }
        int koeficient=(r-1)*n+c;
        int index=1;
        while(true)
        {
            if(koeficient>counter[index].size())
            {
                koeficient-=counter[index].size();
                index++;
            }
            else
            {
                cout<<counter[index][koeficient-1]<<"\n";
                break;
            }

        }
    }


}
