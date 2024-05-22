#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>> vecs;
int main()
{
   int maxZnamenatel;
   long long int result=0;
     int copyI=0;
    int copyK=0;
   cin>>maxZnamenatel;
   for(int i=2;i<=maxZnamenatel;i++)
   {
       for(int k=1;k<i;k++)
       {
           vecs[i].push_back(k);
       }
   }
   for(int i=2;i<=maxZnamenatel;i++)
   {
       result+=vecs[i].size();
       if(i==maxZnamenatel)
       {
           break;
       }
       while(vecs[i].size()!=0)
       {
           vecs[i].erase(vecs[i].begin());
           int copyI=i;
           int copyK=vecs[i][0];
           int beginK=copyK;
           while(copyI+i<=maxZnamenatel)
           {
                copyI+=i;copyK+=beginK;
                vecs[copyI].erase(vecs[copyI].begin()+1);
           }
       }
   }
   cout<<result+1;
}
