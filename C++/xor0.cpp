#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> foundZeros;
int n;
int main()
{
cin>>n;
int result=0;
long long int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
    if(arr[i]==0)
    {
        result++;
    }
}
for(int i=0;i<n;i++)
{
    if(foundZeros[i]!=0)
    {
        result+=foundZeros[i];
        continue;
    }
    int num=arr[i];
    int calculateNextIndex=-1;
    for(int k=i+1;k<n;k++)
    {
        num^=arr[k];
        if(num==0)
        {
            result++;
            foundZeros[i]++;
            if(calculateNextIndex==-1)
            {
                calculateNextIndex=k;
            }
            else{
                foundZeros[calculateNextIndex]++;
            }
        }
    }
}
cout<<result;
}

