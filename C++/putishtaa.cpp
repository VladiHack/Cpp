#include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    vector<pair<int,int>> vec;
    int start=-1;int endIndex=-1;bool found=false;
                   int n;int m;
                   bool met[10000];
    void Recursion(int pos)
    {
        if(pos==endIndex||found)
        {
            found=true;
            return;
        }
        for(int i=0;i<vec.size();i++)
        {
            if((vec[i].first==start||vec[i].second==start)&&(vec[i].first==endIndex||vec[i].second==endIndex))
            {
                continue;
            }
            if(vec[i].first==pos)
            {
               if(!met[vec[i].second])
                {
                   met[vec[i].second]=true;
                Recursion(vec[i].second);
               }
            }
            if(vec[i].second==pos)
            {
               if(!met[vec[i].first])
               {
                   met[vec[i].first]=true;
                Recursion(vec[i].first);
               }
            }
        }
    }
    int main()
    {
          int t;
               cin>>t;
        for(int s=0;s<t;s++)
        {
               cin>>n>>m;
               vec.clear();
               for(int i=0;i<m;i++)
               {
                   int street1;int street2;
                   cin>>street1>>street2;
                   if(street1>street2)
                   {
                       int x=street1;
                       street1=street2;
                       street2=x;
                   }
                   pair<int,int> newP;
                   newP.first=street1;newP.second=street2;
                   vec.push_back(newP);
               }

               for(int i=0;i<m;i++)
               {
                   memset(met,false,sizeof(met));
                   found=false;start=vec[i].first;endIndex=vec[i].second;
                   met[vec[i].first]=true;
                   Recursion(vec[i].first);
                   if(found==false)
                   {
                       cout<<vec[i].first<<" "<<vec[i].second<<"\n";
                   }
               }
        }


    }
