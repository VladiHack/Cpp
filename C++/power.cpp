#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}
long long int fastPow(int num, int power) {
    if (power == 0)
        return 1;
    long long int half = fastPow(num, power >> 1);
    long long int squared = ((long long int)half * half);
    return (power & 1) ? ((long long int)squared * num) : squared;
}
int B;int k;int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    bool calculated[50];
    memset(calculated,false,sizeof(calculated));
    int arr[n];
    cin>>arr[0];
    B=arr[0];
    for(int i=1;i<n;i++)
    {
        cin>>arr[i];
    }
    long long int counter=1;
    while(true)
    {
        long long int num=counter;
        for(int i=0;i<k-1;i++)
        {
            num*=counter;
        }
        bool met=true;
        for(int i=0;i<n;i++)
        {
            if(num%arr[i]!=0)
            {
                met=false;
                break;
            }
        }
        if(met)
        {
          cout<<counter;
          break;
        }
        counter++;
    }
}
