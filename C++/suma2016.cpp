#include <iostream>
#include <bits/stdc++.h>
void GetCombinations(int arr[],int n,int pos,int prev);
void PrintArray(int num[],int n);
using namespace std;
int main()
{
int nums;
cin>>nums;
int arr[nums];
for(int i=0;i<nums;i++)
{
    cin>>arr[i];
}
GetCombinations(arr,nums-1,0,-1);
}

void GetCombinations(int arr[],int n,int pos,int prev)
{
    if(pos==n-1)
    {
       PrintArray(arr,n);
    }
    else
    {
        for(int i=prev+1;i<n;i++)
        {
            GetCombinations(arr,n,pos+1,i);
        }
    }
}
void PrintArray(int num[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<"\n";
}

