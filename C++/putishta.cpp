 #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    vector<pair<int,int>> vec;
    int start=-1;int endIndex=-1;bool found=false;
                   int n;int m;
    void Recursion(int pos,bool met[])
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
                     bool copyMet[n+1];
                   copy(met,met+n+1,copyMet);
                   copyMet[vec[i].second]=true;
                Recursion(vec[i].second,copyMet);
               }
            }
            if(vec[i].second==pos)
            {
               if(!met[vec[i].first])
               {
                   bool copyMet[n+1];
                   copy(met,met+n+1,copyMet);
                   copyMet[vec[i].first]=true;
                Recursion(vec[i].first,copyMet);
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
                   bool met[n+1];
                   memset(met,false,sizeof(met));
                   found=false;start=vec[i].first;endIndex=vec[i].second;
                   met[vec[i].first]=true;
                   Recursion(vec[i].first,met);
                   if(found==false)
                   {
                       cout<<vec[i].first<<" "<<vec[i].second<<"\n";
                   }
               }
        }


    }
