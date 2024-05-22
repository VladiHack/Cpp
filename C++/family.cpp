#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t;
        cin>>t;
        for(int z=0;z<t;z++)
        {
            int n;int k;
        cin>>n>>k;
        int groupsTotal=0;
        int groupsCopy=0;
        unordered_map<int,int> groups;
        unordered_map<int,vector<int>> groupsVectors;
        vector<bool> met(n,false);
        int taken=0;
        for(int i=0;i<k;i++)
        {
            int firstBall;int secondBall;
            cin>>firstBall>>secondBall;
            firstBall--;secondBall--;
            if(met[firstBall]==true&&met[secondBall]==false)
            {
                groups[secondBall]=groups[firstBall];
                groupsVectors[groups[secondBall]].push_back(secondBall);
                met[secondBall]=true;
                taken++;
            }
            else if(met[secondBall]&&!met[firstBall])
            {
               groups[firstBall]=groups[secondBall];
               groupsVectors[groups[firstBall]].push_back(firstBall);
               met[firstBall]=true;
               taken++;
            }
            else if(met[firstBall]==false&&met[secondBall]==false)
            {
                met[firstBall]=true;
                met[secondBall]=true;
                groups[firstBall]=groupsTotal;
                groups[secondBall]=groupsTotal;
                groupsVectors[groupsTotal].push_back(firstBall);
                groupsVectors[groupsTotal].push_back(secondBall);
                groupsTotal++;
                groupsCopy++;
                taken+=2;
            }
            else
            {
                if(groups[firstBall]!=groups[secondBall])
                {
                    int getValue=groups[firstBall];
                    int getSecond=groups[secondBall];
                    if(groupsVectors[getValue].size()>groupsVectors[getSecond].size())
                    {
                        for(int j=0;j<groupsVectors[getSecond].size();j++)
                        {
                            groupsVectors[getValue].push_back(groupsVectors[getSecond][j]);
                            groups[groupsVectors[getSecond][j]]=getValue;
                        }
                        groupsVectors[getSecond].clear();
                    }
                    else
                    {
                         for(int j=0;j<groupsVectors[getValue].size();j++)
                        {
                            groupsVectors[getSecond].push_back(groupsVectors[getValue][j]);
                            groups[groupsVectors[getValue][j]]=getSecond;
                        }
                        groupsVectors[getValue].clear();
                    }
                    groupsCopy--;

                }
            }
        }
        int biggest=0;
        for(int i=0;i<=groupsTotal;i++)
        {
            int sizer=groupsVectors[i].size();
            biggest=max(biggest,sizer);
        }
        cout<<biggest<<"\n";
        }

}
