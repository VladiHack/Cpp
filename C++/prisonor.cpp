#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int ways=0;int maxSteps=0;
int n;int m;
long long int arr[1000][1000];
int main()
{
    cin>>n>>m;
    maxSteps=m+n-1;
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<m;k++)
        {
         cin>>arr[i][k];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<m;k++)
        {
            if(i==0&&k!=0)
            {
                if(arr[i][k-1]==0)
                {
                    arr[i][k]=0;
                }
            }
            else if(i!=0&&k==0)
            {
                if(arr[i-1][k]==0)
                {
                    arr[i][k]=0;
                }
            }
            else if(i!=0&&k!=0&&arr[i][k]!=0)
            {
                arr[i][k]=arr[i-1][k]+arr[i][k-1];
            }
        }
    }

    if(arr[n-1][m-1]==0)
    {
        cout<<"Impossible";
    }
    else
    {
    cout<<arr[n-1][m-1];
    }
}
/*void FindPaths(int x,int y,int stepsSoFar )
{
    if((x==n&&y==m)||maxSteps<stepsSoFar)
    {
        if(maxSteps>=stepsSoFar)
        {
            ways++;
        }
        return;
    }
    if(x!=0&&y!=0&&arr[x][y]!=0)
    {
        arr[x][y]=arr[x-1[y]+arr[x][y-1];
    }

}
*/

