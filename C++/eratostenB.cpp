#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int left;int right;
  cin>>left>>right;
 long long int wordSize=right;
  vector<bool> primes(right+1,true);
  vector<int> primeCopy;
  for(long long int p=2;p<=wordSize;p++)
  {
      if(primes[p])
      {
          primeCopy.push_back(p);
          for(long long int i=p*p;i<=wordSize;i+=p)
          {
              primes[i]=false;
          }
      }
  }
  string msg="no prime";
  for(int i=left;i<=right;i++)
  {
      if(primes[i])
      {
          int sumDigits=0;
          int copyNum=i;
          while(copyNum!=0)
          {
              sumDigits+=copyNum%10;
              copyNum/=10;
          }
          if(primes[sumDigits]&&sumDigits>9)
          {
            cout<<i<<" ";
          }
      }
  }
}
