#include<iostream>
#include <bits/stdc++.h>
using namespace std;
long long int prMax=0;
long long int dp[201][201];
void Recursion(int suma,long long int pr,int num);
int main(int argc, char argv[])
{
int suma;
cin>>suma;
for(int i=0;i<suma;i++)
{
    for(int k=0;k<suma;k++)
    {
        dp[i][k]=-1;
    }
}
Recursion(suma,1,2);
cout<<prMax;

}
void Recursion(int suma,long long int pr,int num)
{
    if(suma<=1||num>suma||dp[suma][num]>pr)
    {
        prMax=max(prMax,pr);
        return;
    }
    dp[suma][num]=pr;
    if(suma-num>=0)
    {
        Recursion(suma-num,pr*num,num+1);
        Recursion(suma,pr,num+1);
    }
    else
    {
        Recursion(suma,pr,num+1);
    }
}
