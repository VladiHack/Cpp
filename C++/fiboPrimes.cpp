#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void FindWay(long long int currentNum,int foundPrime,int arr[]);
bool isPrime(long long int currentNum);
int maxFound=0;
long long int n;
long long int result=0;

int main()
{
cin>>n;
int arr[n/2+1];
arr[0]=2;
arr[1]=3;
for(int i=2;i<=n/2;i++)
{
    arr[i]=arr[i-1]+arr[i-2];
}
FindWay(n,0,arr);
cout<<maxFound;
}
void FindWay(long long int currentNum,int foundPrime,int arr[])
{
    if(currentNum<=1)
    {
        maxFound=max(maxFound,foundPrime);
        return;
    }
    for(int i=0;i<=n/2+1;i++)
    {
        if(arr[i]<=currentNum)
        {
            if(isPrime(currentNum)&&currentNum!=1)
            {
                foundPrime++;
            }
            currentNum/=arr[i];
            FindWay(currentNum,foundPrime,arr);
        }
        else{
            break;
        }
    }
}
bool isPrime(long long int currentNum)
{
    for(int i=2;i<=sqrt(currentNum);i++)
    {
        if(currentNum%i==0)
        {
            return false;
        }
    }
    return true;
}

