#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int n;int m;int k;
long long int variations=0;
int dp[51][51];
void Recursion(int last,int length)
{
    if(dp[last][length]!=-1)
    {
        variations+=dp[last][length];
        return;
    }
    if(length==n)
    {
        variations++;
        return;
    }
    if(last+k<m)
    {
        long long int copyVars=variations;
        Recursion(last+k,length+1);
        dp[last+k][length+1]=variations-copyVars;
    }
    if(last-k>=1)
    {
        long long int copyVars=variations;
        Recursion(last-k,length+1);
        dp[last-k][length+1]=variations-copyVars;

    }
}
int main(int argc, char argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k>>m>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<m;i++)
    {
        Recursion(i,1);
    }
    cout<<variations;
}
