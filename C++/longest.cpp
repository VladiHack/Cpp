    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;

    int shortestPath=INT_MAX;
    vector<int> vec[2001];
    vector<int> cols[2001];
    void Recursion(int distance,int x,int y,int desiredX,int DesiredY)
    {
        if(shortestPath<=distance)return;
           if(x==desiredX&&y==DesiredY)
           {
               shortestPath=distance;
               return;
           }
           for(int i=0;i<vec[x].size();i++)
           {
               Recursion(distance+abs(vec[x][i]-y),x,vec[x][y],desiredX,DesiredY);
           }
           for(int i=0;i<vec[y].size();i++)
           {
                Recursion(distance+abs(vec[y][i]-x),vec[y][i],y,desiredX,DesiredY);
           }
    }
    int main()
    {
       int n;
       cin>>n;
       for(int i=0;i<n;i++)
       {
           int city1;int city2;
           cin>>city1>>city2;
           vec[city1].push_back(city2);
           cols[city2].push_back(city1);
       }
      for(int i=0;i<)
    }
