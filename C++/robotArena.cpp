#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
   int n;int r;
   int m; int k;
    cin>>m;
   cin>>n;
   cin>>r;
   cin>>k;
   int arr[m][n];
   memset( arr, 0, sizeof(arr) );
   bool recentlyAdded[m][n];
   memset(recentlyAdded,false,sizeof(recentlyAdded));
   long long int sum=0;
   r--;
   int rowStart=r/n;
   int colStart=r%n;
   r++;
   arr[rowStart][colStart]=r;
   while(k>0)
   {
          for(int i=0;i<m;i++)
          {
              for(int j=0;j<n;j++)
              {
                  if(arr[i][j]!=0&&recentlyAdded[i][j]==false)
                  {
                      if(i>0&&arr[i-1][j]==0)
                      {
                          arr[i-1][j]=(i-1)*n+j+1;
                          sum+=arr[i-1][j];
                      }
                      if(i<m-1&&arr[i+1][j]==0)
                      {
                          arr[i+1][j]=(i+1)*n+j+1;
                          recentlyAdded[i+1][j]=true;
                          sum+=arr[i+1][j];
                      }
                      if(j>0&&arr[i][j-1]==0)
                      {
                          arr[i][j-1]=i*n+j;
                          sum+=arr[i][j-1];
                      }
                      if(j<n-1&&arr[i][j+1]==0)
                      {
                          arr[i][j+1]=i*n+j+2;
                          recentlyAdded[i][j+1]=true;
                          sum+=arr[i][j+1];
                      }
                  }
              }
          }
        k-=1;
           memset(recentlyAdded,false,sizeof(recentlyAdded));


   }
   arr[rowStart][colStart]=0;
  for(int i=0;i<m;i++)
          {
              for(int j=0;j<n;j++)
              {
                  cout<<arr[i][j]<<" ";
              }
             cout<<"\n";
          }

          cout<<sum;
}
