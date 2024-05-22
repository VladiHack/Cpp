#include<iostream>
using namespace std;
int main(int argc, char argv[])
{
    int n;int a;int b;
    cin>>n>>a>>b;
    int dp[b+1];
    memset(dp,2000000,sizeof(dp));
    int arr[n][3];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i][0];
        cin>>arr[i][1];
        cin>>arr[i][2];
    }
    for(int i=0;i<n;i++)
    {
        int start=arr[i][0];
        int ends=arr[i][1];
        int cost=arr[i][2];
       dp[start]=min()
    }

}
