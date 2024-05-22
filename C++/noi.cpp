#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char argv[])
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;int h;
        cin>>n>>h;
        int arr[n];
        long long int v=0;
        for(int s=0;s<n;s++)
        {
            int num;
            cin>>num;
            arr[s]=num;
            v+=100*arr[s];
            if(s!=0&&s!=n-1)
            {
               if(arr[s]<h)
                {
                    v+=(h-arr[s])*100;
                }
            }
        }
        cout<<v<<"\n";

    }
}
