#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int k;
    cin>>n;
    cin>>k;
    vector<pair<int,int>> paths;
            pair<int,int> current;
    for(int i=0;i<n-1;i++)
    {
        int from;int to;
        cin>>from>>to;
        current.first=from;
        current.second=to;
        paths.push_back(current);
    }
     sort(paths.begin(), paths.end());
    for(int i=0;i<k;i++)
    {
        int from;int to;
        cin>>from>>to;
        for(int i=0;i<paths.size();i++)
        {
            if(paths[i].first==from)
            {

            }
        }
    }
}

