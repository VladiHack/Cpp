#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
   int otsechki;
   cin>>otsechki;
   int arr[otsechki][2];
   int countMet=0;
   int countLongest=0;
   int longestRight=0;
   int crossed[100000];
   memset(crossed,0,100000);
   for(int i=0;i<otsechki;i++)
   {
       int left;
       int right;
       cin>>left;
       cin>>right;
       longestRight=max(longestRight,right);
       for(int k=left;k<=right;k++)
       {
           crossed[k]++;
       }
   }
   int counter=0;
   for(int i=0;i<=longestRight;i++)
   {
       if(crossed[i]==1)
       {
           if(counter==0)
           {
               countMet++;
           }
           counter++;
       }
       else
       {
        countLongest=max(countLongest,counter);
        counter=0;
       }
   }
   for(int i=0;i<=longestRight;i++)
   {
       cout<<i<<":value=>"<<crossed[i]<<"\n";
   }
   cout<<countMet<<" "<<countLongest;

}
