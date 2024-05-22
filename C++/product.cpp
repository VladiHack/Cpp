#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  int n;
  cin>>n;
  unordered_map<int,int> arr;
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  int biggest=-1;
    long long int compare=0;
  long long int maxRes=0;
  for(int i=0;i<n;i++)
  {
      if(arr[i]>biggest)
      {
          biggest=arr[i];
          for(int j=0;j<n;j++)
          {
              if(arr[j]<arr[i])
              {
                  compare=arr[j];
                  compare*=(j-i);
              }
              else
              {
                compare=arr[i];
                compare*=(j-i);
              }
              if(compare<0)
              {
                  compare*=-1;
              }
              if(maxRes<compare)
              {
                  maxRes=compare;
              }
          }
      }
  }
  cout<<maxRes;

}

