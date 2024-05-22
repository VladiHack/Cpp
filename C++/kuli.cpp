#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unordered_map<int,unordered_map<int,bool>> met;
int main()
{
int n;int k;
cin>>n>>k;
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
int calc=0;
for(int i=0;i<n-1;i++)
{
   for(int s=i+1;s<n;s++)
   {
       int biggest=max(arr[i],arr[s]);
       int copyK=k;
       for(int k=i;k<=s;k++)
       {
           if(arr[k]>biggest)
           {
               copyK--;
               if(copyK==0)
               {
                   break;
               }
           }
           calc++;
       }
   }
}

cout<<calc;
}
