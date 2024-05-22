#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sergii;
    int razgovori;
    cin>>sergii>>razgovori;
    razgovori++;
    int positive=0;
    long long int arr[sergii];
    long long int sum;
    for(int i=0;i<sergii;i++)
    {
        cin>>arr[i];
        if(arr[i]>0)
        {
            positive++;
        }
    }
    if(positive<=razgovori)
    {
        for(int i=0;i<sergii;i++)
        {
            if(arr[i]>0)
            {
                sum+=arr[i]*-1;
            }
            else{
                sum+=arr[i];
            }
        }
    }
    else {
        for(int i=0;i<razgovori;i++)
        {
            int biggestIndex=0;
            for(int j=0;j<sergii;j++)
            {
                if(arr[j]>arr[biggestIndex])
                {
                    biggestIndex=j;
                }
            }
            arr[biggestIndex]*=-1;
        }
        for(int i=0;i<sergii;i++)
        {
            sum+=arr[i];
        }
    }
    cout<<sum;
}
