#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int numbers;int questions;
    cin>>numbers>>questions;
    int arr[numbers];
    int question[questions];
    for(int i=0;i<numbers;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<questions;i++)
    {
        int left;int right;int divider;
        int counter=0;
        cin>>left>>right>>divider;
        for(int k=left-1;k<right;k++)
        {
            if(arr[k]%divider==0||divider%arr[k]==0)
            {
                counter++;
            }
        }
        question[i]=counter;
    }
    for(int i=0;i<questions;i++)
    {
        cout<<question[i]<<" ";
    }
}
