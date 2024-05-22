#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int n;
cin>>n;
unordered_map <int,vector<int>> arr;
int read[n];
for(int i=0;i<n;i++)
{
    cin>>read[i];
}
  int s = sizeof(read) / sizeof(read[0]);
        sort(read, read + s);
for(int i=0;i<n;i++)
{
    int num=read[i];
    unordered_map<int,bool> takenValues;
    vector<int> toAdd;
    for(int k=0;k<i;k++)
    {
        if(takenValues[read[k]]==false)
        {
             if(num%read[k]==0)
            {
                toAdd.push_back(read[k]);
                takenValues[read[k]]=true;
                for(int j=0;j<arr[k].size();j++)
                {
                    toAdd.push_back(arr[k][j]);
                    takenValues[arr[k][j]]=true;
                }
            }
        }
        else{
            break;
        }

    }
    arr[num]=toAdd;
}
long long int sumAll=0;
for(int i=0;i<n;i++)
{
    int num=read[i];
    vector<int> vec=arr[num];
    for(int k=0;k<vec.size();k++)
    {
        sumAll+=arr[vec[k]].size();
    }
}
cout<<sumAll;


}
