#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;int pricePerWeek;
int moneyMax=0;
unordered_map<int,int> dp;
bool worthBuying[301];
long long int calcPrice=0;
void Recursion(int index,int arr[],int tonsCurrently,int s,int buyPrice,int sellPrice)
{
    calcPrice=sellPrice-buyPrice-pricePerWeek*s;
    moneyMax=max(moneyMax,calcPrice);
    if(index==n||n-index-tonsCurrently<0)
    {
        return;
    }
    if(dp[tonsCurrently]>=calcPrice&&dp[tonsCurrently]!=0)
    {
        return;
    }
    dp[tonsCurrently]=calcPrice;
    s+=tonsCurrently;
    if(worthBuying[index])
    {
         Recursion(index+1,arr,tonsCurrently+1,s,buyPrice+arr[index],sellPrice);
    }
    if(tonsCurrently>0)
    {
        Recursion(index+1,arr,tonsCurrently-1,s,buyPrice,sellPrice+arr[index]);
    }
    Recursion(index+1,arr,tonsCurrently,s,buyPrice,sellPrice);

}
int main(int argc, char *argv[])
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>n>>pricePerWeek;
int arr[n];
memset(worthBuying,false,sizeof(worthBuying));
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
for(int i=0;i<n;i++)
{
    for(int k=i+1;k<n;k++)
    {
        if(arr[k]>arr[i])
        {
         worthBuying[i]=true;
         break;
        }
    }
}
Recursion(0,arr,0,0,0,0);
cout<<moneyMax;
}
