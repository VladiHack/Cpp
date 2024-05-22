#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int n;bool found=false;
 vector<pair<int,int>> first;
vector<pair<int,int>> second;
void Recursion(int index,bool met[])
{
    if(found)
    {
        return;
    }
    if(index==n)
    {
        found=true;
        cout<<"Yes\n";
        for(int i=0;i<n;i++)
        {
            cout<<index[i]<<"\n";
        }
        return;
    }
    bool firstConcert=true;bool secondConcert=false;
    for(int i=first[index].first;i<=first[index].second;i++)
    {
        if(met[i])
        {
            firstConcert=false;
            break;
        }
    }
    for(int i=second[index].first;i<=second[index].second;i++)
    {
        if(met[i])
        {
            secondConcert=false;
            break;
        }
    }
    if(firstConcert)
    {

    }
}
int main(int argc, char argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    pair<int,int> newP;
    int a;int b;int c;int d;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>c>>d;
        newP.first=a;newP.second=b;
        first.push_back(newP);
        newP.first=c;newP.second=d;
        second.push_back(newP);
    }
}
