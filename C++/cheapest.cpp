#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int res=0;
    int countResult=0;
    for(int i=2;i<n;i++)
    {
        bool Prime=true;
        for(int k=2;k<=i/2;k++)
        {
            if(i%k==0)
            {
                Prime=false;
                break;
            }
        }
        if(Prime==true)
        {
            arr[res]=i;
            res++;
        }
    }
    for(int i=0;i<res;i++)
    {
        for(int k=0;k<res;k++)
        {
            if(arr[i]+arr[k]==n)
            {
                countResult++;
            }
        }
    }
    cout<<countResult;

}
