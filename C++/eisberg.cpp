#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int n;int m;
int arr[303][303];
bool dp[303][303];
void Recursion(int row,int col)
{
    dp[row][col]=true;
    if(arr[row+1][col]!=-1&&arr[row+1][col]!=0&&dp[row+1][col]==false)
    {
        Recursion(row+1,col);
    }
    if(arr[row+1][col+1]!=-1&&arr[row+1][col+1]!=0&&dp[row+1][col+1]==false)
    {
        Recursion(row+1,col+1);
    }
    if(arr[row][col+1]!=-1&&arr[row][col+1]!=0&&dp[row][col+1]==false)
    {
        Recursion(row,col+1);
    }
    if(arr[row-1][col]!=-1&&arr[row-1][col]!=0&&dp[row-1][col]==false)
    {
        Recursion(row+1,col);
    }
     if(arr[row][col-1]!=-1&&arr[row][col-1]!=0&&dp[row][col-1]==false)
    {
        Recursion(row,col+1);
    }
     if(arr[row-1][col-1]!=-1&&arr[row-1][col-1]!=0&&dp[row][col-1]==false)
    {
        Recursion(row-1,col-1);
    }
     if(arr[row-1][col+1]!=-1&&arr[row-1][col+1]!=0&&dp[row-1][col+1]==false)
    {
        Recursion(row-1,col+1);
    }
     if(arr[row+1][col-1]!=-1&&arr[row+1][col-1]!=0&&dp[row+1][col-1]==false)
    {
        Recursion(row+1,col-1);
    }
}
int main(int argc, char argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    memset(arr,-1,sizeof(arr));
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=m;k++)
        {
            cin>>arr[i][k];
        }
    }
            int months=0;
    while(true)
    {
        memset(dp,false,sizeof(dp));
        int counter=0;
        for(int i=1;i<=n;i++)
        {
            for(int k=1;k<=m;k++)
            {
                if(dp[i][k]==false&&arr[i][k]!=-1&&arr[i][k]!=0)
                {
                    if(counter==1)
                    {
                        cout<<months;
                        return 0;
                    }
                    counter++;
                    Recursion(i,k);
                }
            }
        }
        months++;
     for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=m;k++)
        {
            if(arr[i][k]>0)
            {
                if(arr[i-1][k]==0)
                {
                    arr[i][k]--;
                }
                if(arr[i][k-1]==0)
                {
                    arr[i][k]--;
                }
                if(arr[i][k+1]==0)
                {
                    arr[i][k]--;
                }
                if(arr[i+1][k]==0)
                {
                    arr[i][k]--;
                }
                if(arr[i][k]<0)
                {
                    arr[i][k]=0;
                }
            }
        }
    }
    }

}
