#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> keepSolutions;
class Graph
{
    int V;
    list<int> *adj;
    void bridgeUtil(int u, vector<bool>& visited, vector<int>& disc,
                                  vector<int>& low, int parent);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void bridge();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
void Graph::bridgeUtil(int u, vector<bool>& visited, vector<int>& disc,
                                  vector<int>& low, int parent)
{
    static int time = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;
          if(v==parent)
            continue;
          if(visited[v]){
          low[u]  = min(low[u], disc[v]);
        }
          else{
          parent = u;
          bridgeUtil(v, visited, disc, low, parent);
          low[u]  = min(low[u], low[v]);
          if (low[v] > disc[u])
              {
                  pair<int,int> newP;
                  newP.first=u;newP.second=v;
                  keepSolutions.push_back(newP);
              }

        }
    }
}

void Graph::bridge()
{
        vector<bool> visited (V,false);
    vector<int> disc (V,-1);
      vector<int> low (V,-1);
      int parent = -1;
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent);
}
int main()
{
   int t;
   cin>>t;

   for(int i=0;i<t;i++)
   {
          int n;int m;
        cin>>n>>m;
        keepSolutions.clear();
        Graph g(4004001);
        vector<pair<int,int>> pairs;
        for(int s=0;s<m;s++)
        {
            int num1;int num2;
            cin>>num1>>num2;
            pair<int,int> newP;
            if(num1>num2)
            {
                int x=num1;
                num1=num2;
                num2=x;
            }
            newP.first=num1;newP.second=num2;
            pairs.push_back(newP);
            g.addEdge(num1,num2);
        }
      g.bridge();
      sort(pairs.begin(),pairs.end());
      for(int s=0;s<m;s++)
      {
          for(int k=0;k<keepSolutions.size();k++)
          {
              if((pairs[s].first==keepSolutions[k].first&&pairs[s].second==keepSolutions[k].second)||(pairs[s].first==keepSolutions[k].second&&pairs[s].second==keepSolutions[k].first))
              {
                  cout<<pairs[s].first<<" "<<pairs[s].second<<"\n";
                  break;
              }
          }
      }
   }
}
