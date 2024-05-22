#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int minSteps=15;
bool met=false;
vector<long long int> arr;
unordered_map<int,unordered_map<long long int,int>> dp;
unordered_map<int,unordered_map<long long int,bool>>met;
long long int n;
void Recursion(int steps,long long int sum,int index)
{
    if(index==arr.size()||steps>=minSteps)
    {
        return;
    }
    if(met[index][sum]&&dp[index][sum]<=steps)
    {
        return;
    }
    met[index][sum]=true;
    dp[index][sum]=steps;
     if(sum==0)
    {
        met=true;
        minSteps=min(steps,minSteps);
        return;
    }
    Recursion(steps,sum,index+1);
    if(sum-arr[index]>=0)
    {
        Recursion(steps+1,sum-arr[index],index+1);
    }
}
int main()
{
cin>>n;
long long int first=1;
arr.push_back(first);
while(first<=n)
{
    if(first%2==0)
    {
        first=first<<1;
        first++;
    }
    else{
        first=first<<1;
    }
    arr.push_back(first);
}
Recursion(0,n,0);
if(!met)
{
    cout<<-1;
}
else{
    cout<<minSteps;
}
}
