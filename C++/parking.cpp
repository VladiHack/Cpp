#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int n;int m;
bool met[501][501];
string res="NO";
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>m;
        memset(met,false,sizeof(met));
        for(int s=0;s<n;s++)
        {
            for(int z=0;z<m;z++)
            {
                char sign;
                cin>>sign;
                if(sign=='.')
                {
                    met[s][z]=true;
                }
            }
        }
        int x1;int y1;int x2;int y2;
        cin>>x1>>y1>>x2>>y2;
        x1--;y1--;x2--;y2--;

    }
}

