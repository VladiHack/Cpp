#include<iostream>
#include <bits/stdc++.h>
using namespace std;
string res="no kravaiche";
bool met=false;
int n;int k;
int arr[100000];
unordered_map<int,unordered_map<int,bool>> dp;
void Recursion(int index,int sum,string kushti)
{
    bool benZero=true;
    if(met)
    {
        return;
    }
      if(sum>=k)
    {
        sum=sum%k;
        benZero=false;
    }
    if(sum==0&&!benZero)
    {
        met=true;
      res=kushti;
      return;
    }
    if(index==n||dp[index][sum])
    {
        return;
    }
    dp[index][sum]=true;

    Recursion(index+1,sum,kushti);
    Recursion(index+1,sum+arr[index],kushti+to_string(index+1)+" ");
}
int main(int argc, char argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
cin>>k>>n;
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
Recursion(0,0,"");
cout<<res;
}
