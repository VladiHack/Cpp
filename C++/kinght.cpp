#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
int row;int col;int x;int y;
cin>>row>>col>>x>>y;
unordered_map<int,unordered_map<int,bool>> met;
int counter=0;
while(true)
{
    met[x][y]=true;
    counter++;
    if(x-2>0&&y-1>0&&met[x-2][y-1]==false)
    {
        x-=2;
        y-=1;
        continue;
    }
    if(x-2>0&&y+1<=col&&met[x-2][y+1]==false)
    {
        x-=2;
        y+=1;
        continue;
    }
    if(x-1>0&&y-2>0&&met[x-1][y-2]==false)
    {
        x-=1;
        y-=2;
        continue;
    }
    if(x-1>0&&y+2<=col&&met[x-1][y+2]==false)
    {
        x-=1;
        y+=2;
        continue;
    }
    if(x+1<=row&&y-2>0&&met[x+1][y-2]==false)
    {
        x+=1;
        y-=2;
        continue;
    }
    if(x+1<=row&&y+2<=col&&met[x+1][y+2]==false)
    {
        x+=1;
        y+=2;
        continue;
    }
    if(x+2<=row&&y-1>0&&met[x+2][y-1]==false)
    {
        x+=2;
        y-=1;
        continue;
    }
    if(x+2<=row&&y+1<=col&&met[x+2][y+1]==false)
    {
        x+=2;
        y+=1;
        continue;
    }
    break;
}
cout<<counter;
}
