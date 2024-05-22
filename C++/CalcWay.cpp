
#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    cin.tie(0);
    long long int nums;
    long long int pos;
    cin>>nums>>pos;
    vector<long long int> sums;
    vector<long long int> arr1;
    vector<long long int> arr2;
    for(int i=0;i<nums;i++)
    {
        long long int num1;
        cin>>num1;
        arr1.push_back(num1);
    }
    for(int i=0;i<nums;i++)
    {
        long long int num2;
        cin>>num2;
        arr2.push_back(num2);
    }
    for(int i=0;i<nums;i++)
    {
        for(int k=0;k<nums;k++)
        {
            sums.push_back(arr1[i]+arr2[k]);
        }
    }
     sort(sums.begin(), sums.end());
     cout<<sums[pos-1];

}



