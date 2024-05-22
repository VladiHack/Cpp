#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int n;int m;int houses;
int res=-1;
char arr[2001][2001];
int dp[2001][2001][18];
void Recursion(int x,int y,string housesC,int steps)
{
    cout<<x<<" "<<y<<" "<<housesC<<"\n";
    if((steps>res&&res!=-1)||arr[x][y]=='X')
    {
        return;
    }
    if(arr[x][y]=='T')
    {
        if(housesC.size()==houses)
        {
             if(res==-1||res>steps)
             {
                 res=steps;
             }
             return;
        }
    }
    if(housesC.size()==0||housesC.size()==houses)
    {
        if((dp[x][y][housesC.size()]==-1||dp[x][y][housesC.size()]>steps))
    {
        dp[x][y][housesC.size()]=steps;
    }
    else{
        return;
    }
    }

    bool add=false;
    if(arr[x][y]!='P'&&arr[x][y]!='X'&&arr[x][y]!='T'&&arr[x][y]!='*')
    {
       if(housesC.find(arr[x][y])<housesC.length())
       {
           //Nishto
       }
       else{
            add=true;
       }
    }
    if(x>0)
    {
        if(add)
        {
            Recursion(x-1,y,housesC+arr[x][y],steps+1);
        }
        else{
                 Recursion(x-1,y,housesC,steps+1);
        }
    }
    if(x<n-1)
    {
        if(add)
        {
        Recursion(x+1,y,housesC+arr[x][y],steps+1);
        }
        else{
                        Recursion(x+1,y,housesC,steps+1);
        }
    }
    if(y>0)
    {
        if(add)
        {
                   Recursion(x,y-1,housesC+arr[x][y],steps+1);
        }
        else{
       Recursion(x,y-1,housesC,steps+1);
        }
    }
    if(y<m-1)
    {
        if(add)
        {
                    Recursion(x,y+1,housesC+arr[x][y],steps+1);
        }
        else{
                    Recursion(x,y+1,housesC,steps+1);
        }
    }
}
int main(int argc, char *argv[])
{
  cin>>m>>n>>houses;
  memset(dp,-1,sizeof(dp));
  int x=0;int y=0;
  for(int i=0;i<n;i++)
  {
     string read;
     cin>>read;
     for(int s=0;s<m;s++)
     {
         arr[i][s]=read[s];
         if(arr[i][s]=='P')
         {
             x=i;
             y=s;
         }
     }
  }
  Recursion(x,y,"",0);
  cout<<res*10;
}
