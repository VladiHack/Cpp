#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int minSteps=INT_MAX;int n;
unordered_map<int,unordered_map<int,bool>> exist;
int dp[2001][2001];
void Recursion(int x,int y,int steps,unordered_map<int,unordered_map<int,bool>> met,int uniqueMet)
{
   if(x<-1000||x>1000)
   return;
   if(y<-1000||y>1000)
   return;
   if(minSteps<=steps)
   return;
   if(dp[x+1000][y+1000]!=-1&&dp[x+1000][y+1000]<=steps)
   {
       return;
   }
   dp[x+1000][y+1000]=steps;
   if(exist[x][y]&&met[x][y]==false)
   {
      if(uniqueMet==n-1)
      {
          minSteps=steps;
          return;
      }
      met[x][y]=true;
      Recursion(x+1,y+1,steps+1,met,uniqueMet+1);
      met[x][y]=false;
       met[x][y]=true;
      Recursion(x+1,y+1,steps+1,met,uniqueMet+1);
      met[x][y]=false;
       met[x][y]=true;
      Recursion(x-1,y+1,steps+1,met,uniqueMet+1);
      met[x][y]=false;
       met[x][y]=true;
      Recursion(x-1,y-1,steps+1,met,uniqueMet+1);
      met[x][y]=false;
   }
   else{
     Recursion(x+1,y+1,steps+1,met,uniqueMet);
     Recursion(x+1,y+1,steps+1,met,uniqueMet);
     Recursion(x-1,y+1,steps+1,met,uniqueMet);
     Recursion(x-1,y-1,steps+1,met,uniqueMet);
   }
}
int main()
{
cin>>n;
memset(dp,-1,sizeof(dp));
for(int i=0;i<2*n;i++)
{
    int f;int s;
    cin>>f>>s;
    exist[f][s]=true;
}
unordered_map<int,unordered_map<int,bool>> met;
Recursion(0,0,0,met,0);
cout<<minSteps;
}
