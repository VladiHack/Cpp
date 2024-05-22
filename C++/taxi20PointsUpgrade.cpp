#include <bits/stdc++.h>
using namespace std;
int n;vector<vector<int>> vec(1001);
vector<int> res;
unordered_map<int,unordered_map<int,int>> dp;
unordered_map<int,unordered_map<int,bool>> metDp;
int minDistance;
void FindPahts(int lastCity,bool metCities[],int filledUnique,vector<int> trip,int steps)
    {
    if(steps+(n-filledUnique)>minDistance)
    {
        return;
    }
    if(metDp[lastCity][filledUnique]&&dp[lastCity][filledUnique]<=steps)
    {
        return;
    }
    metDp[lastCity][filledUnique]=true;
    dp[lastCity][filledUnique]=steps;
     if(filledUnique==n)
    {
       res=trip;
        minDistance=steps;
        return;
    }
        for(int i=0;i<vec[lastCity].size();i++)
        {
        int num=vec[lastCity][i];
        if(!metCities[num])
        {
                metCities[num]=true;
                trip.push_back(num);
                FindPahts(num,metCities,filledUnique+1,trip,steps+1);
                metCities[num]=false;
                trip.pop_back();
        }
        else
        {
            trip.push_back(num);
            FindPahts(num,metCities,filledUnique,trip,steps+1);
            trip.pop_back();
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
        int mostMetNum=0;int mostMetTimes=0;

    for(int i=1;i<=n;i++)
    {
        if(vec[i].size()<times)
        {
            times=vec[i].size();
            smallest=i;
        }
         if(vec[i].size()>mostMetTimes)
        {
            mostMetTimes=vec[i].size();
            mostMetNum=i;
        }
    }
    bool metIndexes[n+1];
    memset(metIndexes,false,sizeof(metIndexes));
    metIndexes[smallest]=true;
    vector<int> trip;
    trip.push_back(smallest);
    FindPahts(smallest,metIndexes,1,trip,1);
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
            for(int i=1;i<=n;i++)
            {
                cout<<val[i]<<" ";
            }
            cout<<"sum="<<sum<<"\n";
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
