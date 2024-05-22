#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
unordered_map<int,vector<int>> arr;
unordered_map<int,unordered_map<int,bool>> met;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>n;
for(int i=1;i<=n;i++)
{
    for(int k=1;k<=n;k++)
    {
        if(i!=k)
        {
            arr[i].push_back(k);
        }
    }
}
int res=0;
for(int i=1;i<n;i++)
{
    int left;int right;
    cin>>left>>right;
    arr[left].push_back(right);
    arr[right].push_back(left);
    met[left][right]=true;
    met[left][left]=true;
    met[right][right]=true;
    met[right][left]=true;
}
for(int i=1;i<=n;i++)
{
    int countNotDirect=0;
    bool metFalseOnce=false;
    for(int k=0;k<arr[i].size();k++)
    {
        for(int s=k+1;s<arr[i].size();s++)
        {
            if(met[arr[i][k]][arr[i][s]]==false)
            {
                res++;
                metFalseOnce=true;

            }
        }
    }
    if(metFalseOnce==false)
    {
        break;
    }
}
cout<<res;
}
