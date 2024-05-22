#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> res;
int filledUnique=1;
bool metCitiesAlready[1001];
int diffCities=0;
unordered_map<int,unordered_map<int,bool>> isBridge;
class Graph
{
    int V;
    vector<int> *adj;
    void bridgeUtil(int u, vector<bool>& visited, vector<int>& disc,
                                  vector<int>& low, int parent);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void bridge();
    void findBestPath(int currentCity,bool met[]);
    void FindBridgeSize(int from);
    int giveSize(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V+1];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
void Graph::findBestPath(int currentCity,bool met[])
{
    int indexBridge=-1;int smallestBridgeSize=INT_MAX;
    int indexAny=-1;   int sizeSecondBridge;
    int secondCity=0;
    int lastIndex=-1;
    while(filledUnique!=n)
    {
        indexBridge=-1;
        indexAny=-1;
        smallestBridgeSize=INT_MAX;
        currentCity=res[res.size()-1];
        if(met[currentCity]==false)
        {
            filledUnique++;
            met[currentCity]=true;
            if(filledUnique==n)
            {
                return;
            }
        }
        for(int i=0;i<adj[currentCity].size();i++)
        {
            secondCity=adj[currentCity][i];
            if(met[secondCity]==false)
            {
                if(isBridge[currentCity][secondCity])
                {
                    memset(metCitiesAlready,false,sizeof(metCitiesAlready));
                    metCitiesAlready[currentCity]=true;
                    diffCities=0;
                    FindBridgeSize(secondCity);
                    sizeSecondBridge=diffCities;
                     if(sizeSecondBridge>smallestBridgeSize)
                     {
                         indexBridge=secondCity;
                         smallestBridgeSize=sizeSecondBridge;
                     }
                }
                else
                {
                    indexAny=secondCity;
                }
            }
        }

        if(indexBridge!=-1)
        {
            res.push_back(indexBridge);
            lastIndex=res.size()-2;
        }
        else if(indexAny!=-1)
        {
            res.push_back(indexAny);
            lastIndex=res.size()-2;
        }
        else
        {
            res.push_back(res[lastIndex]);
            lastIndex--;
        }
    }
}
void Graph::FindBridgeSize(int current)
{
    if(metCitiesAlready[current])
    {
        return;
    }
    metCitiesAlready[current]=true;
    diffCities++;
    for(int i=0;i<adj[current].size();i++)
    {
        FindBridgeSize(adj[current][i]);
    }
}

void Graph::bridgeUtil(int u, vector<bool>& visited, vector<int>& disc,
                                  vector<int>& low, int parent)
{

    static int time = 0;

    visited[u] = true;

    disc[u] = low[u] = ++time;

    list<int>::iterator i;
    for (int i = 0; i <adj[u].size(); ++i)
    {
        int v = adj[u][i];

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
                isBridge[u][v]=true;
              isBridge[v][u]=true;
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
int Graph::giveSize(int v)
{
    return adj[v].size();
}
int main()
{
    /*
    freopen("taxi.in","r",stdin);
    freopen("taxi.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    */
    int m;
    cin>>n>>m;
    Graph vec(n+1);
    vector<int> cities(n);
    for(int i=0;i<n;i++)
    {
        cin>>cities[i];
    }
    sort(cities.begin(),cities.end());
    int city1;int city2;
    for(int i=0;i<m;i++)
    {
        cin>>city1>>city2;
        vec.addEdge(city1,city2);
    }
    vec.bridge();
    int smallest=-1;int times=n*n;
    int mostMetNum=0;int mostMetTimes=0;
    for(int i=1;i<=n;i++)
    {
        if(vec.giveSize(i)<times)
        {
            times=vec.giveSize(i);
            smallest=i;
        }
        if(mostMetTimes<vec.giveSize(i))
        {
            mostMetNum=i;
            mostMetTimes=vec.giveSize(i);
        }
    }
    int mostMet=0;
    bool metIndexes[n+1];
    memset(metIndexes,false,sizeof(metIndexes));
    metIndexes[smallest]=true;
    res.push_back(smallest);
    vec.findBestPath(smallest,metIndexes);
    int indexer=0;
    int sum=0;
    int bestSum=INT_MAX;
    int bestOrder[n+1];int val[n+1];
    int temp=0;
    int takeNum;
    memset(bestOrder,0,sizeof(bestOrder));
    for(int s=0;s<n;s++)
    {
         memset(val,0,sizeof(val));
         takeNum=cities[s];
         val[mostMetNum]=takeNum;
         indexer=0;
         sum=0;
            for(int i=0;i<res.size();i++)
            {
                if(val[res[i]]==0)
                {
                    if(indexer==s)
                    {
                        indexer++;
                    }
                    val[res[i]]=cities[indexer];
                    indexer++;
                }
                if(i!=0)
                {
                    sum+=((val[res[i]]-val[res[i-1]])*(val[res[i]]-val[res[i-1]]));
                    if(sum>bestSum)
                    {
                        break;
                    }
                }
            }
            if(sum<bestSum)
            {
                for(int i=1;i<=n;i++)
                {
                    temp=val[i];
                    bestOrder[i]=temp;
                }
                bestSum=sum;
            }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<bestOrder[i]<<" ";
    }
    cout<<"\n";
     vector<string> cityOutput;
    bool met[n+1];
    memset(met,false,sizeof(met));
    int metThatDay=0;
    string numsRemember="";
    for(int i=0;i<res.size();i++)
    {
        int num=res[i];
        if(met[num])
        {
            if(i-metThatDay!=0)
            {
                metThatDay+=1;
            }
            string finalee=to_string(metThatDay)+" "+numsRemember;
            cityOutput.push_back(finalee);
            metThatDay=1;
            memset(met,false,sizeof(met));
            met[num]=true;
            numsRemember=to_string(res[i-1])+" ";
            numsRemember+=to_string(num)+" ";
        }
        else
        {
            metThatDay++;
            met[num]=true;
            numsRemember+=to_string(num)+" ";
        }
    }
    if(res.size()-metThatDay!=0)
    {
       metThatDay+=1;
    }
    string finalee=to_string(metThatDay)+" "+numsRemember;
    cityOutput.push_back(finalee);
    cout<<cityOutput.size()<<"\n";
    for(int i=0;i<cityOutput.size();i++)
    {
        cout<<cityOutput[i]<<"\n";
    }
}
