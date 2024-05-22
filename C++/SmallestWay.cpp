#include<iostream>
using namespace std;
int main(int argc, char argv[])
{
    int rows;int cols;
    cin>>rows>>cols;
    int arr[rows][cols];
    int dp[rows][cols];
    fill((int*)arr,(int*)arr+sizeof(arr)/sizeof(int),0);
 fill((int*)dp,(int*)dp+sizeof(dp)/sizeof(int),0);
    for(int i=0;i<rows;i++)
    {
        for(int k=0;k<cols;k++)
        {
            cin>>arr[i][k];
            if(k==0&&i==0)
            {
                dp[0][0]=arr[0][0];
                continue;
            }
            else if(k==0)
            {
                dp[i][k]=dp[i-1][k]+arr[i][k];
                continue;
            }
            else if(i==0)
            {
                dp[i][k]=dp[i][k-1]+arr[i][k];
            }
        }
    }
    for(int i=1;i<rows;i++)
    {
        for(int k=1;k<cols;k++)
        {
            dp[i][k]=min(dp[i][k-1],dp[i-1][k])+arr[i][k];
        }
    }
    cout<<dp[rows-1][cols-1];
}
