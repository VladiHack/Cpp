#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int rows;int columns;
   cin>>rows>>columns;
   int arr[rows+1][columns+1];
   fill((int*)arr,(int*)arr+sizeof(arr)/sizeof(int),0);
   arr[0][0]=1;
   for(int i=1;i<=rows;i++)
   {
       for(int k=1;k<=columns;k++)
       {
           if(i==1&&k==1)
           {
               arr[i][k]=1;
           }
           else{
            arr[i][k]=arr[i-1][k]+arr[i][k-1];
           }

       }
   }
   cout<<arr[rows][columns];
}

