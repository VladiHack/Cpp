#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int variations=0;
int n;int k;
int dp[800][800];
void Recursion(int workers,int remainingExhibition,int prev,int current)
{
    if(workers==0)
    {
        variations++;
        return;
    }
    if(current>prev)
    {
        return;
    }
    Recursion(workers-1,remainingExhibition,prev,current+1);
    if(remainingExhibition!=0)
    {
       Recursion(workers,remainingExhibition-1,current,0);
    }
}
int main()
{
cin>>n>>k;
memset(dp,-1,sizeof(dp));
n-=k;
Recursion(n,k,n+1,0);
cout<<variations;
}
