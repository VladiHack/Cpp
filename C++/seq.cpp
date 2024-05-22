#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int n;int m;int k;
int met=0;
int dp[50][50];
int Recursion(int index,int included);
int main(int argc, char argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
cin>>k>>m>>n;
memset(dp,-1,sizeof(dp));
for(int i=0;i<m;i++)
{
    for(int k=0;k<n;k++)
    {
        cout<<dp[i][k]<<" ";
    }
    cout<<"\n";
}
for(int i=1;i<m;i++)
{
    Recursion(i,1);
}
for(int i=0;i<m;i++)
{
    for(int k=0;k<n;k++)
    {
        cout<<dp[i][k]<<" ";
    }
    cout<<"\n";
}
}
int Recursion(int index,int included)
{
    if(index==n)
    {
        return 1;
    }
    if(dp[index][included]!=-1)
       {
           met+=dp[index][included];
           return dp[index][included];
       }

   if(index+k<m&&index-k>0)
   {

       dp[index][included]=Recursion(index+k,included+1)+Recursion(index-k,included+1);
   }
   else if(index+k<m&&index-k<=0)
   {
       dp[index][included]=Recursion(index+k,included+1);
   }
   else if(index-k>0)
   {
     dp[index][included]=Recursion(index-k,included+1);
   }
}

