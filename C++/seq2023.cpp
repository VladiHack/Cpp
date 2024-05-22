#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void FindCombos(int arr[],int nums);
int n;int m;int k;
long long int result=0;

int main()
{
cin>>n>>m>>k;
int arr[m+1]{0};
FindCombos(arr,0);
cout<<result;
}
void FindCombos(int arr[],int nums)
{
    if(nums==n)
    {
        result++;
        for(int i=1;i<=m;i++)
        {
            cout<<i<<":"<<arr[i]<<"\n";
            arr[i]=0;
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=m;i++)
    {
        if(arr[i]<k)
        {
            arr[i]++;
            FindCombos(arr,nums+1);
        }

    }
}

