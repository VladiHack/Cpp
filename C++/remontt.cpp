#include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    int n;int m;
    vector<int> vec[2001];int timesVisited[2001];
    int pathsFound=0;
   vector<pair<int,int>> indexes;
    void dfs(int visited[2001],int u,int v,vector<int> path)
    {
        visited[u]=1;
        if(u==v)
        {
            for(int i=1;i<path.size();i++)
            {
                int prev=path[i-1];
                for(int s=0;s<m;s++)
                {
                    if((indexes[s].first==prev&&indexes[s].second==path[i])||(indexes[s].second==prev&&indexes[s].first==path[i]))
                    {
                        timesVisited[s]++;
                        break;
                    }
                }
            }
            pathsFound++;
        }

        else
        {
            for(int i=0;i<vec[u].size();i++)
            {
                int y=vec[u][i];
                if(visited[y]==0)
                {
                    visited[y]=1;
                    path.push_back(y);
                    dfs(visited,y,v,path);
                    path.pop_back();
                }
            }
        }
        visited[u]=0;


    }
    int main()
    {
          int t;
        cin>>t;
        for(int s=0;s<t;s++)
        {
            indexes.clear();
               cin>>n>>m;
               for(int i=1;i<=2001;i++)
               {
                   vec[i].clear();
               }
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
                   pair<int,int> p;
                   p.first=street1;p.second=street2;
                   indexes.push_back(p);
                   vec[street1].push_back(street2);
                   vec[street2].push_back(street1);
               }
              vector<int> path;
              int visited[2001];
              memset(visited,0,sizeof(visited));
              int u=1;int v=n;
              memset(timesVisited,0,sizeof(timesVisited));
              path.push_back(1);
pathsFound=0;
              dfs(visited,u,v,path);
              for(int i=0;i<m;i++)
              {
                  if(timesVisited[i]==pathsFound)
                  {
                      cout<<indexes[i].first<<" "<<indexes[i].second<<"\n";
                  }
              }

        }


    }
