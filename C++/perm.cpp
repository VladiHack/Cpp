#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
int n;int times;
cin>>n>>times;
int arr[n+1];
for(int i=1;i<=n;i++)
{
    cin>>arr[i];
}
int temp[n+1];
for(int i=0;i<times;i++)
{
    for(int k=1;k<=n;k++)
    {
        temp[arr[k]]=arr[k];
    }
    for(int k=1;k<=n;k++)
    {
        arr[k]=temp[k];
    }
}
for(int i=1;i<=n;i++)
{
    cout<<arr[i]<<" ";
}
}
