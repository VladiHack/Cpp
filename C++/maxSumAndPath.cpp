#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;int m;
    cin>>n>>m;
    int arr[n][m];
    int dp[n][m];
    string result="";
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
    cout<<dp[n-1][m-1]<<"\n";
    int row=n-1;int col=m-1;
    while(true)
    {
        if(row==0&&col==0)
        {
            break;
        }
        if(row!=0&&col!=0)
        {
            if(dp[row-1][col]>dp[row][col-1])
            {
                result+='D';
                row--;
            }
            else{
                result+='R';
                col--;
            }
        }
        else if(col==0)
        {
            while(row!=0)
            {
                result+='D';
                row--;
            }
        }
        else if(row==0)
        {
            while(col!=0)
            {
                result+='R';
                col--;
            }
        }
    }
    for(int i=0;i<result.size();i++)
    {
    cout<<result[result.size()-1-i];
    }
    /*
    1 1 2 1
    2 2 1 1
    2 1 2 1
    */
}


