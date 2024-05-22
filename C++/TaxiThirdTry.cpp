#include <bits/stdc++.h>
using namespace std;
int n;vector<vector<int>> vec(1001);
vector<int> res;
vector<string> allWaysSoFar;
vector<int> stepsAtWays;
int minDistance;
void FindPahts(int lastCity,string rememberPath,int filledUnique,vector<int> trip,int steps)
    {
    if(steps+(n-filledUnique)>minDistance)
    {
        return;
    }
    bool contains=false;
     for(int i=0;i<allWaysSoFar.size();i++)
     {
         if(allWaysSoFar[i]==rememberPath)
         {
             if(stepsAtWays[i]<=steps)
             {
                 return;
             }
             stepsAtWays[i]=steps;
             contains=true;
             break;
         }
     }
     if(contains==false)
     {
        allWaysSoFar.push_back(rememberPath);
        stepsAtWays.push_back(steps);
     }
     if(filledUnique==n)
    {
       res=trip;
        minDistance=steps;
        return;
    }
        for(int i=0;i<vec[lastCity].size();i++)
        {
        int num=vec[lastCity][i];
        if(rememberPath[num]=='e')
        {
                rememberPath[num]++;
                trip.push_back(num);
                FindPahts(num,rememberPath,filledUnique+1,trip,steps+1);
                rememberPath[num]--;
                trip.pop_back();
        }
        else
        {
            trip.push_back(num);
            rememberPath[num]++;
            FindPahts(num,rememberPath,filledUnique,trip,steps+1);
            rememberPath[num]--;
            trip.pop_back();
        }
    }
}
int main()
{

    freopen("taxi.in","r",stdin);
    freopen("taxi.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin>>n>>m;
    vector<int> cities(n);
    minDistance=n*n;
    for(int i=0;i<n;i++)
    {
        cin>>cities[i];
    }
    sort(cities.begin(),cities.end());
    int city1;int city2;
    for(int i=0;i<m;i++)
    {
        cin>>city1>>city2;
        vec[city1].push_back(city2);
        vec[city2].push_back(city1);
    }
    int smallest=-1;int times=n*n;
    for(int i=1;i<=n;i++)
    {
        if(vec[i].size()<times)
        {
            times=vec[i].size();
            smallest=i;
        }
    }
    int mostMet=0;
    string rememberPath(n+1,'e');
    rememberPath[smallest]='e'+1;
    vector<int> trip;
    trip.push_back(smallest);
    FindPahts(smallest,rememberPath,1,trip,1);
    int val[n+1];
    memset(val,0,sizeof(val));
    val[res[0]]=cities[0];
    int indexer=1;
    for(int i=1;i<res.size();i++)
    {
        if(val[res[i]]==0)
        {
            val[res[i]]=cities[indexer];
            indexer++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<val[i]<<" ";
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
