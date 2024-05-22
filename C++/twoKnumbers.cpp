#include <iostream>
using namespace std;
int n;int k;
int sum=0;
int dp[2][30];
void Recursion(bool lastZero,int pos,int times)
{
    if(pos==n)
    {
        sum+=times;
        return;
    }
    if(times==0)
    {
        Recursion(false,1,k-1);
    }
    else if(lastZero)
    {
        if(dp[1][pos+1]==-1)
        {
            int copyRes=sum;
            Recursion(false,pos+1,times*(k-1));
            dp[1][pos+1]=sum-copyRes;
        }
        else{
            sum+=dp[1][pos+1];
        }
    }
    else{
        if(dp[1][pos+1]==-1)
        {
            int copyRes=sum;
            Recursion(false,pos+1,times*(k-1));
            dp[1][pos+1]=sum-copyRes;
        }
        else{
            sum+=dp[1][pos+1];
        }
    if(dp[0][pos+1]==-1)
    {
        int copyRes=sum;
                Recursion(true,pos+1,times);
                dp[0][pos+1]=sum-copyRes;
    }
    else{
        sum+=dp[0][pos+1];
    }
    }
}
int main()
{
    for(int i=0;i<2;i++)
    {
        for(int k=0;k<30;k++)
        {
            dp[i][k]=-1;
        }
    }
    cin>>n>>k;
    Recursion(false,0,0);
    cout<<sum;
}
