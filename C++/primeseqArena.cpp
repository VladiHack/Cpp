#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool checkPrime(long long int number);
int main()
{
  int tests;
  cin>>tests;
  for(int i=0;i<tests;i++)
  {
     long long int number;
     cin>>number;

  }
}
bool checkPrime(long long int number)
{
    for(int i=2;i<=sqrt(number);i++)
    {
        if(number%i==0)
        {
            return false;
        }
    }
    return true;
}
void FindCombos(long long int number,int k)
{

}

