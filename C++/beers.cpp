#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    while(true)
    {
      int n;int s;
        cin>>n>>s;
        if(n==0&&s==0)
        {
            break;
        }
        vector<int> arr;
        for(int i=0;i<n;i++)
        {
            int num;
            cin>>num;
            arr.push_back(num);
        }
        int counter=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            int suma=s;
            if(s<arr[i])
            {
                break;
            }
            suma-=arr[i];
            for(int s=n-1;s>i;s--)
            {
                if(suma>=arr[s])
                {
                   counter+=s-i;
                   break;
                }
            }
        }
        cout<<counter<<"\n";
    }

}
