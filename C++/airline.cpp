    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    vector<int> cities[1001];
     int shortest[1001][1001];
     int starting;
    void Recursion(int current,int distance)
    {
        if(shortest[starting][current]!=-1&&shortest[starting][current]<=distance)
        {
            return;
        }
        shortest[starting][current]=distance;
        for(int i=0;i<cities[current].size();i++)
        {
            int next=cities[current][i];
            Recursion(next,distance+1);
        }
    }
    int main()
    {
        int n;
        cin>>n;
       memset(shortest,-1,sizeof(shortest));
        for(int i=0;i<n-1;i++)
        {
            int startCity;int endCity;
            cin>>startCity>>endCity;
            cities[startCity].push_back(endCity);
            cities[endCity].push_back(startCity);
        }
        for(int i=1;i<=n;i++)
        {
            starting=i;
            Recursion(i,0);
        }
        vector<int> keepShortest;
        int longestShort=INT_MAX;
        for(int i=1;i<=n;i++)
        {
            int cLongest=0;
            for(int s=1;s<=n;s++)
            {
              cLongest=max(cLongest,shortest[i][s]);
            }
            if(cLongest==longestShort)
            {
                keepShortest.push_back(i);
            }
            else if(cLongest<longestShort)
            {
                longestShort=cLongest;
                keepShortest.clear();
                keepShortest.push_back(i);
            }
        }
        cout<<keepShortest.size()<<"\n";
        for(int i=0;i<keepShortest.size();i++)
        {
            cout<<keepShortest[i]<<" ";
        }
    }
