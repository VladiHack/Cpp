#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void Cheapest(int endRow,int endColumn);
int dp[21][21];
int arr[21][21];
int main()
{
  int rows;
  int columns;
  cin>>rows>>columns;
  fill((int*)dp,(int*)dp+sizeof(dp)/sizeof(int),0);
  for(int i=1;i<=rows;i++)
  {
      for(int k=1;k<=columns;k++)
      {
          cin>>arr[i][k];
      }
  }
    dp[1][1]=arr[1][1];
  cout<<dp[rows,columns];

}
int Cheapest(int endRow,int endColumn)
{
    if(endRow==1&&endColumn==1)
    {
return dp[1][1];
 }
    dp[endRow][endColumn]=min(Cheapest(endRow-1,endColumn),Cheapest(endRow,endColumn))+arr[endRow][endColumn];
}

