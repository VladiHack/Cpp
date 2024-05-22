#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int biggestSum=0;
int takeTwo[100000];
int takeThree[100000];
void Recursion(int arr[],int index,int sum,bool lastThree);
int main(int argc, char argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
Recursion(arr,0,0,false);
cout<<biggestSum;
memset(takeTwo,-600000,sizeof(takeTwo));
memset(takeThree,-600000,sizeof(takeThree));

}
void Recursion(int arr[],int index,int sum,bool lastThree)
{
   if(index==n)
   {
       biggestSum=max(sum,biggestSum);
       return;
   }
   if(index>0)
   {
       if(lastThree)
   {
       if(takeThree[index]>sum)
       {
           return;
       }
       takeThree[index]=sum;
   }
   if(!lastThree)
   {
       if(takeTwo[index]>sum)
       {
           return;
       }
       takeTwo[index]=sum;
   }
   }

   if(lastThree||arr[index]<=0)
   {
        Recursion(arr,index+1,sum+arr[index]*2,false);
   }
   else
   {
        Recursion(arr,index+1,sum+arr[index]*2,false);
        Recursion(arr,index+1,sum+arr[index]*3,true);
   }
}
