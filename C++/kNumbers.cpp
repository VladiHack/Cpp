#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;int k;
int sum=0;
void Recursion(bool lastZero,int pos,int times)
{
    if(pos==n)
    {
        sum+=times;
        return;
    }
    if(times==0)
    {
        Recursion(false,1,k-1);
    }
    else if(lastZero)
    {
       Recursion(false,pos+1,times*(k-1));
    }
    else{
        Recursion(true,pos+1,times);
        Recursion(false,pos+1,times*(k-1));
    }
}
int main()
{
    cin>>n>>k;
    Recursion(false,0,0);
    cout<<sum;
}
