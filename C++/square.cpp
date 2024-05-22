#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int arr[32][32];
int main()
{
int t;
cin>>t;
memset(arr,0,sizeof(arr));
arr[1][1]=1;
for(int i=1;i<=31;i++)
{
    for(int k=1;k<=31;k++)
    {
        arr[i][k]+=arr[i-1][k]+arr[i][k-1];
        cout<<arr[i][k]<<" ";
    }
    cout<<"\n";
}
for(int i=0;i<t;i++)
{
    int n;
    cin>>n;
    n++;
    cout<<arr[n][n]<<"\n";
}

}
