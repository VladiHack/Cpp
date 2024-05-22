#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int first;int second;
int lifts;long long int minSum=LLONG_MAX;
int diff;
int rows;
void Recursion(int indexQuery,int elevatorInfo[],int from[],int to[],long long int sumThusFar,int freeElevators)
{
    if(sumThusFar>=minSum)
    {
        return;
    }
    if(indexQuery==rows)
    {
        minSum=sumThusFar;
    }
    for(int i=0;i<lifts;i++)
    {
        if(elevatorInfo[i]==-1)
        {
            elevatorInfo[i]=to[indexQuery];
            Recursion(indexQuery+1,elevatorInfo,from,to,sumThusFar,freeElevators-1);
            elevatorInfo[i]=-1;
        }
        else if(freeElevators<rows-indexQuery)
        {
         int keepPrevFloor=elevatorInfo[i];
         int diff=abs(elevatorInfo[i]-from[indexQuery]);
         elevatorInfo[i]=to[indexQuery];
         Recursion(indexQuery+1,elevatorInfo,from,to,sumThusFar+diff,freeElevators);
         elevatorInfo[i]=keepPrevFloor;
        }
    }
}
int main()
{
    cin>>rows>>lifts;
    int from[rows];int to[rows];
    for(int i=0;i<rows;i++)
    {
        cin>>from[i]>>to[i];
    }
    int liftRemember[lifts];
    memset(liftRemember,-1,sizeof(liftRemember));
    Recursion(0,liftRemember,from,to,0,lifts);
    cout<<minSum;
}
