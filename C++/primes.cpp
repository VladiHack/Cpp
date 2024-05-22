#include<iostream>
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char argv[])
{

 bool prime[1000000];
 int longestVeriga=0;
    memset(prime, true, sizeof(prime));
  int left;int n;
  cin>>left>>n;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    int countPrimes=0;
vector<int> result;
    prime[1]=false;
    for(int i=left;i<=n;i++)
    {
        if(prime[i]==true)
        {
            int firstIndex=2;
            while(firstIndex!=-1)
            {
                int firstMetPrime=-1;
                int copyI=i;
                 vector<int> vec;
                for(int l=firstIndex;l<=i;l++)
                {
                    if(prime[l]==true)
                    {
                       vec.push_back(l);
                       copyI-=l;
                         if(copyI<0)
                       {
                           break;
                       }
                       if(copyI==0)
                       {
                           if(vec.size()>longestVeriga)
                           {
                               int vecSize=vec.size();
                               result.clear();
                               result.push_back(i);
                               result.push_back(vecSize);
                               for(int j=0;j<vecSize;j++)
                               {
                                   int number=vec[j];
                                   result.push_back(number);
                               }
                            longestVeriga=vecSize;
                           }
                       }
                       if(l!=firstIndex&&firstMetPrime==-1)
                       {
                         firstMetPrime=l;
                       }

                    }
                }
                firstIndex=firstMetPrime;
            }
        }
    }
    if(result.size()!=0)
    {
        for(int i=0;i<result.size();i++)
        {
            cout<<result[i]<<" ";
            if(i==1)
            {
                cout<<"\n";
            }
        }


        return 1;
    }
    cout<<"no prime";

}
