#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unordered_map<long long int,unordered_map<long long int,bool>> dp;
int times=0;
int main()
{
    int n;
  cin>>n;
  int arr[n];
  long long int sumGiven=0;
  for(int i=0;i<n;i++)
  {
      cin>>arr[i];
      sumGiven+=arr[i];
  }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=true;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sumGiven;j++)
        {
            if(arr[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
            }
        }
    }

    for(long long int i=sumGiven/2;i>=0;i--)
    {
        if(dp[n][i])
        {
           cout<<min(i,sumGiven-i)<<"\n";
           break;
        }
    }
}
