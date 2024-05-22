// A C++ program to find bridges in a given undirected graph
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> keepSolutions;
// A class that represents an undirected graph
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
    void bridgeUtil(int u, vector<bool>& visited, vector<int>& disc,
                                  vector<int>& low, int parent);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    void bridge();    // prints all bridges
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}

// A recursive function that finds and prints bridges using
// DFS traversal
// u --> The vertex to be visited next
// visited[] --> keeps track of visited vertices
// disc[] --> Stores discovery times of visited vertices
// parent[] --> Stores parent vertices in DFS tree
void Graph::bridgeUtil(int u, vector<bool>& visited, vector<int>& disc,
                                  vector<int>& low, int parent)
{
    // A static variable is used for simplicity, we can
    // avoid use of static variable by passing a pointer.
    static int time = 0;

    // Mark the current node as visited
    visited[u] = true;

    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;

    // Go through all vertices adjacent to this
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;  // v is current adjacent of u

          // 1. If v is parent
          if(v==parent)
            continue;

          //2. If v is visited
          if(visited[v]){
          low[u]  = min(low[u], disc[v]);
        }

          //3. If v is not visited
          else{
          parent = u;
          bridgeUtil(v, visited, disc, low, parent);

          // update the low of u as it's quite possible
          // a connection exists from v's descendants to u
          low[u]  = min(low[u], low[v]);

          // if the lowest possible time to reach vertex v
          // is greater than discovery time of u it means
          // that v can be only be reached by vertex above v
          // so if that edge is removed v can't be reached so it's a bridge
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
        Graph g(2002);
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
              if(pairs[s].first==keepSolutions[k].first&&pairs[s].second==keepSolutions[k].second)
              {
                  cout<<pairs[s].first<<" "<<pairs[s].second<<"\n";
                  break;
              }
          }
      }
   }

    return 0;
}
