#include<iostream>
#include <bits/stdc++.h>
using namespace std;
 unordered_map<int,vector<int>> boss;
       unordered_map<int,bool> isBoss;
              unordered_map<int,int> bossSlaves;
              void Recursion(int currentBoss);

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
       int n;
       cin>>n;

       for(int i=0;i<n-1;i++)
       {
           int cboss;int cslave;
           cin>>cboss>>cslave;
           boss[cboss].push_back(cslave);
           isBoss[cboss]=true;
       }
       for(int i=1;i<=n;i++)
       {
           if(isBoss[i])
           {
               if(bossSlaves[i]==0)
               {
                   Recursion(i);
               }
           }
       }
        int q;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            int pos;
            cin>>pos;
            cout<<bossSlaves[pos]<<"\n";
        }

}
void Recursion(int currentBoss)
{
    for(int i=0;i<boss[currentBoss].size();i++)
    {
        if(isBoss[boss[currentBoss][i]])
        {
            if(bossSlaves[boss[currentBoss][i]]==0)
            {
                Recursion(boss[currentBoss][i]);
            }
            bossSlaves[currentBoss]+=bossSlaves[boss[currentBoss][i]];
        }
        bossSlaves[currentBoss]+=1;
    }
}
