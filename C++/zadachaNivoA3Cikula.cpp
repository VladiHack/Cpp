#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
    int number;
    cin>>number;
    int arr[number];
    long long int result=0;
    for(int i=0;i<number;i++)
    {
        cin>>arr[i];
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    for(int i=0;i<number;i++)
    {
        for(int k=i+1;k<number;k++)
        {
            if(arr[k]%arr[i]==0)
            {
                for(int j=k+1;j<number;j++)
                {
                    if(arr[j]%arr[k]==0)
                    {
                        result++;
                    }
                }
            }
        }
    }
    cout<<result;
}
