#include<iostream>
#include <bits/stdc++.h>
using namespace std;

long long int result=0;
void FindPaths(int currentSum,bool foundSums[],int arr[],int left,int right,int n);
int main(int argc, char *argv[])
{
    int n;
int left;
int right;
   cin>>n;
    cin>>left;
   cin>>right;
   int arr[n];
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   bool foundSums[10000]{false};

   FindPaths(0,foundSums,arr,left,right,n);
     for(int i=0;i<100;i++)
   {
       cout<<i<<" "<<foundSums[i]<<"\n";
   }
   cout<<result;
}
void FindPaths(int currentSum,bool foundSums[],int arr[],int left,int right,int n)
{
    if(foundSums[currentSum]==false&&currentSum<=right&&currentSum>=left)
    {
        foundSums[currentSum]=true;
        result++;
    }
    if(currentSum>=right)
    {
        return;
    }
    for(int i=0;i<n;i++)
    {
        FindPaths(currentSum+arr[i],foundSums,arr,left,right,n);
    }
}
