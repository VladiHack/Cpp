#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;int m;
    cin>>n>>m;
    int arr[n][m];
    int dp[n][m];
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<m;k++)
        {
            cin>>arr[i][k];
            if(i==0&&k==0)
            {
                dp[i][k]=arr[i][k];
            }
            else if(k==0&&i!=0)
            {
                dp[i][k]=dp[i-1][k]+arr[i][k];
            }
            else if(k!=0&&i==0)
            {
                dp[i][k]=dp[i][k-1]+arr[i][k];
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int k=1;k<m;k++)
        {
            dp[i][k]=max(dp[i-1][k],dp[i][k-1])+arr[i][k];
        }
    }
    cout<<dp[n-1][m-1];
    /*
    1 1 2 1
    2 2 1 1
    2 1 2 1
    */
}


