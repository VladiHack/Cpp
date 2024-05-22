#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool arr[21][21];
int n;
void Recursion(int row,int col)
{
    bool canPlaceQueen=true;
    for(int i=1;i<=n;i++)
    {
        if(arr[row][i]||arr[i][col])
        {
            canPlaceQueen=false;
            break;
        }
    }
    int newR=row;int newCol=col;
    while(newR<=20&&newCol<=20)
    {
        if(arr[newR][newCol])
        {
            canPlaceQueen=false;
            break;
        }
        newR++;newCol++;
    }
    newR=row;newCol=col;
    while(newR<=20&&newCol>=1)
    {
        if(arr[newR][newCol])
        {
            canPlaceQueen=false;
            break;
        }
        newR++;newCol--;
    }
    newR=row;newCol=col;
    while(newR>=1&&newCol>=1)
    {
        if(arr[newR][newCol])
        {
            canPlaceQueen=false;
            break;
        }
        newR--;newCol--;
    }
     newR=row;newCol=col;
    while(newR>=1&&newCol<=20)
    {
        if(arr[newR][newCol])
        {
            canPlaceQueen=false;
            break;
        }
        newR--;newCol++;
    }
    if(canPlaceQueen)
    {
       arr[row][col]=true;
    }
    Recursion()
}
int main()
{
cin>>n;
memset(arr,false,sizeof(arr));

}
