#include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    int constant=1000001;
    vector<int> arr(constant);
    void SieveOfEratosthenes(long long int n)
    {
       vector<bool> prime(constant);

        for (long long int p = 2; p * p <= n; p++)
          {
            if (prime[p] == false)
            {
                arr[p]++;
                for (long long int i = p*2; i <= n/2; i += p)
                    {prime[i] = true;
                    arr[i]++;
                    }
            }
        }
        for(long long int p=2;p<=n;p++)
        {
            if(arr[p]==0)
            {
                arr[p]=1;
            }
        }
    }
    int main()
    {
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        arr[1]=1;
        SieveOfEratosthenes(constant);
          vector<pair<int,int>> current;
                for(int i=1;i<=constant;i++)
                {
                      pair<int,int> newP;
                      newP.first=arr[i];
                      newP.second=i;
                      current.push_back(newP);
                }
                sort(current.begin(),current.end());
        while(true)
        {
             int n;int r; int c;
            cin>>n;
            if(n==0)
            {
                break;
            }
            cin>>r>>c;
            int koeficient=(r-1)*n+c;
            for(int i=0;i<=constant;i++)
            {
                if(current[i].second<=n*n)
                {
                    koeficient--;
                    if(koeficient==0)
                    {
                        cout<<current[i].second<<"\n";
                        break;
                    }
                }
            }
        }


    }
