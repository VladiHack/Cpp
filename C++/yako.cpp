#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int left;int right;
  cin>>left>>right;
 long long int wordSize=1000;
  vector<bool> primes(1001,true);
  for(long long int p=2;p<=wordSize;p++)
  {
      if(primes[p])
      {
          for(long long int i=p*p;i<=wordSize;i+=p)
          {
              primes[i]=false;
          }
      }
  }
  for(int i=left;i<=right;i++)
  {
      if(primes[i])
      {
         // cout<<i<<"\n";
          int sumDigits=0;
          int copyNum=i;
          while(copyNum!=0)
          {
              sumDigits+=copyNum%10;
              //cout<<copyNum%10<<"\n";
              copyNum/=10;
          }
          if(primes[sumDigits]&&sumDigits>9)
          {
            cout<<i<<" ";
          }
      }
  }
}
