#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> vec;
vector<int> res;
vector<int> cities;
vector<int> timesMetNum;
vector<int> val;
int mostMet;
vector<int> trip;
int minDistance;
unordered_map<int, vector<int>> memo;

void FindPaths(int lastCity, vector<bool>& metCities, int filledUnique, int steps, int prev) {
    if (steps >= minDistance) {
        return;
    }

    if (filledUnique == n) {
        res = trip;
        minDistance = steps;
        return;
    }

    if (memo.count(lastCity) && memo[lastCity].size() >= filledUnique) {
        vector<int>& cachedPath = memo[lastCity];
        if (steps + cachedPath.size() < minDistance) {
            for (int i = 0; i < cachedPath.size(); i++) {
                int city = cachedPath[i];
                if (!metCities[city]) {
                    metCities[city] = true;
                    trip.push_back(city);
                    FindPaths(city, metCities, filledUnique + 1, steps + 1, lastCity);
                    metCities[city] = false;
                    trip.pop_back();
                }
            }
        }
    } else {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].first == lastCity) {
                if (!metCities[vec[i].second]) {
                    metCities[vec[i].second] = true;
                    trip.push_back(vec[i].second);
                    FindPaths(vec[i].second, metCities, filledUnique + 1, steps + 1, lastCity);
                    metCities[vec[i].second] = false;
                    trip.pop_back();
                }
            } else if (vec[i].second == lastCity) {
                if (!metCities[vec[i].first]) {
                    metCities[vec[i].first] = true;
                    trip.push_back(vec[i].first);
                    FindPaths(vec[i].first, metCities, filledUnique + 1, steps + 1, lastCity);
                    metCities[vec[i].first] = false;
                    trip.pop_back();
                }
            }
        }

        if (!memo.count(lastCity) || memo[lastCity].size() < filledUnique) {
            memo[lastCity] = trip;
        }
    }

    if (memo.count(prev) && memo[prev].size() >= filledUnique) {
        vector<int>& cachedPath = memo[prev];
        if (steps + cachedPath.size() < minDistance) {
            for (int i = 0; i < cachedPath.size(); i++) {
                int city = cachedPath[i];
                if (!metCities[city]) {
                    trip.push_back(city);
                    FindPaths(city, metCities, filledUnique, steps + 1, lastCity);
                    trip.pop_back();
                }
            }
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (!metCities[i]) {
                trip.push_back(i);
                FindPaths(i, metCities, filledUnique, steps + 1, lastCity);
                trip.pop_back();
            }
        }

        if (!memo.count(prev) || memo[prev].size() < filledUnique) {
            memo[prev] = trip;
        }
    }
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
    vector<int> cities(n);
    int resulting[n+1];
    minDistance=3*n+n;
    for(int i=0;i<n;i++)
    {
        cin>>cities[i];
    }
    sort(cities.begin(),cities.end());
    int timesMetNum[n+1];
    memset(timesMetNum,0,sizeof(timesMetNum));

    int city1;int city2;
    pair<int,int> newP;
    for(int i=0;i<m;i++)
    {
        cin>>city1>>city2;
        newP.first=city1;newP.second=city2;
        vec.push_back(newP);
        timesMetNum[city1]++;
        timesMetNum[city2]++;
    }
    int smallest=-1;int times=n*n;
    for(int i=1;i<=n;i++)
    {
        if(timesMetNum[i]<times)
        {
            times=timesMetNum[i];
            smallest=i;
        }
    }
    int mostMet=0;
    vector<bool> metIndexes(n+1,false);
    metIndexes[smallest]=true;
    trip.push_back(smallest);
    FindPaths(smallest,metIndexes,1,1,-1);
    int val[n+1];
    memset(val,0,sizeof(val));
    val[res[0]]=cities[0];
    int indexer=1;
    unordered_map<int,int> timesMet;
    for(int i=1;i<res.size();i++)
    {
        timesMet[res[i]]++;
        if(timesMet[res[i]]>mostMet)
        {
            mostMet=timesMet[res[i]];
        }
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
    cout<<mostMet<<"\n";
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
                cout<<metThatDay+1<<" ";
            }
            else{
                cout<<metThatDay<<" ";
            }
            cout<<numsRemember<<"\n";
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
    if(res.size()-metThatDay==0)
    {
         cout<<metThatDay<<" ";
    }
    else
    {
         cout<<metThatDay+1<<" ";
    }
    cout<<numsRemember<<"\n";

}

