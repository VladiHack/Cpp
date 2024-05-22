#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
int n;
cin>>n;
int arr[n];
int sumGiven=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sumGiven+=arr[i];
    }
        bool dp[n+1][sumGiven+1];
        memset(dp,false,sizeof(dp));
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=true;
    }
    for(int i=1;i<=sumGiven;i++)
    {
        dp[0][i]=false;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sumGiven;j++)
        {
            if(arr[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
            }
        }
    }
    int closestDiff=1000000;
    for(int i=sumGiven-1;i>=0;i--)
    {
        if(dp[n][i])
        {
            closestDiff=min(abs(sumGiven-2*i),closestDiff);
        }
    }
    cout<<closestDiff;
}
