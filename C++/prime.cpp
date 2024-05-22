#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  string word;
  cin>>word;
 long long int wordSize=100000;
  vector<bool> primes(100000,true);
  vector<int> primeCopy;
  for(long long int p=2;p<=wordSize;p++)
  {
      if(primes[p])
      {
          primeCopy.push_back(p);
          if(primeCopy.size()==word.size())
          {
              break;
          }
          for(long long int i=p*p;i<=wordSize;i+=p)
          {
              primes[i]=false;
          }
      }
  }
  int counter=0;
  long long int res=0;
  for(int i=0;i<word.size();i++)
  {
      if(word[i]=='1')
      {
          res+=primeCopy[counter];
      }
        counter++;
  }
  cout<<res;
}
