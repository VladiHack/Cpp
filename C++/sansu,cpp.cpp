#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int arr[3][3];
bool checkSansu()
{
    if((arr[0][0]+arr[0][1]+arr[0][2])%3!=0)
    {
        return false;
    }
    if((arr[0][0]+arr[1][0]+arr[2][0])%3!=0)
    {
        return false;
    }
    if((arr[0][0]+arr[1][1]+arr[2][2])%3!=0)
    {
        return false;
    }
    if((arr[0][1]+arr[1][1]+arr[2][1])%3!=0)
    {
        return false;
    }
    if((arr[0][2]+arr[1][2]+arr[2][2])%3!=0)
    {
        return false;
    }
    if((arr[1][0]+arr[1][1]+arr[1][2])%3!=0)
    {
        return false;
    }
    if((arr[2][0]+arr[2][1]+arr[2][2])%3!=0)
    {
        return false;
    }
    if((arr[0][2]+arr[1][1]+arr[2][0])%3!=0)
    {
        return false;
    }
    return true;
}
int main()
{
    for(int i=0;i<3;i++)
    {
        for(int k=0;k<3;k++)
        {
            cin>>arr[i][k];
        }
    }
    bool res=checkSansu();
    cout<<res;
}
