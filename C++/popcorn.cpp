#include<iostream>
#include <bits/stdc++.h>
using namespace std;
 int popcorns;int people;int s;
 int arr[100000];
 int smallestSum=100000;
 void Recursion(int indexPopcorn,int indexPerson,int suma,int maxSum)
 {
    if(indexPerson==people)
    {
           for(int i=indexPopcorn;i<popcorns;i++)
           {
               suma+=arr[i];
           }
           maxSum=max(suma,maxSum);
           smallestSum=min(smallestSum,maxSum);
       return;
    }
    if(indexPopcorn==popcorns)
    {
             maxSum=max(suma,maxSum);
             smallestSum=min(smallestSum,maxSum);
        return;
    }
     maxSum=max(suma,maxSum);
    Recursion(indexPopcorn+1,indexPerson,suma+arr[indexPopcorn],maxSum);
    Recursion(indexPopcorn,indexPerson,arr[indexPopcorn],maxSum);

 }
int main(int argc, char argv[])
{
 cin>>popcorns>>people>>s;
 long long int sum=0;
 for(int i=0;i<popcorns;i++)
 {
     cin>>arr[i];
 }
 Recursion(0,0,0,0);
 if(smallestSum>s)
 {
     if(smallestSum%s==0)
     {
        cout<<smallestSum/s;
     }
     else{
        cout<<smallestSum/s+1;
     }
 }
 else
 {
    cout<<1;
 }
}
