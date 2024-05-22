#include<iostream>
#include <bits/stdc++.h>
using namespace std;
long long int result=0;
int dp[501][501];
void Recursion(int stepsRemaining,int lastSteps,int numberOfSteps)
{
    if(stepsRemaining==0)
    {
        if(numberOfSteps>1)
        {
            result++;
        }
        return;
    }
    for(int i=lastSteps+1;i<=stepsRemaining;i++)
    {
        long long int copyRes=result;
        if(dp[stepsRemaining-i][i]==-1)
        {
                    Recursion(stepsRemaining-i,i,numberOfSteps+1);
                            dp[stepsRemaining-i][i]=result-copyRes;
        }
        else{
            result+=dp[stepsRemaining-i][i];
        }
    }
}
int main(int argc, char argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    Recursion(n,0,0);
    cout<<result;
}
