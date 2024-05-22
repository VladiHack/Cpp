#include<iostream>
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char argv[])
{
 int n;
 cin>>n;
 int arr[n];
 int countNums=0;
long long int left[n];
 long long int right[n];
 memset(left,0,sizeof(left));
 memset(right,0,sizeof(right));
 for(int i=0;i<n;i++)
 {
     cin>>arr[i];
     if(i!=0)
     {
         left[i]+=left[i-1];
     }
     left[i]+=arr[i];
 }
 for(int i=n-1;i>=1;i--)
 {
     if(i!=n-1)
     {
         right[i]+=right[i+1];
     }
     right[i]+=arr[i];
 }

 /*
 for(int i=n/2;i>=1;i--)
 {
     for(int k=i+1;k<n;k++)
     {
         if(left[i]==right[k])
         {
             cout<<i+k;
             return 0;
         }
     }
 }
 */
 for(int i=0;i<n;i++)
 {
     cout<<left[i]<<"\n";
 }
}
