#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void FindWay()
{

}
int main()
{
int t;
int ways;int streets;
cin>>t;
for(int i=0;i<t;i++)
{
    cin>>ways>>streets;
    bool table[streets+1][streets+1];
    memset(table,false,sizeof(table));
    for(int i=0;i<streets;i++)
    {
         int start;int ender;
         cin>>start>>ender;
         table[start][ender]=true;
         table[ender][start]=true;
    }

}

}
