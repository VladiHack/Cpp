#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
int rows;int cols;
int desiredRows;int desiredCols;
cin>>rows>>cols;
cin>>desiredRows>>desiredCols;
vector<pair<int,int>> hashtag;
char read;
for(int i=0;i<rows;i++)
{
    for(int k=0;k<cols;k++)
    {
        cin>>read;
        if(read=='#')
        {
            pair<int,int> newPair;
            newPair.first=i;
            newPair.second=k;
            hashtag.push_back(newPair);
        }
    }
}
int found=0;
for(int i=0;i<rows-desiredRows;i++)
{
    for(int k=0;k<cols-desiredCols;k++)
    {
       bool negative=false;
       for(int s=0;s<hashtag.size();s++)
       {
           if(hashtag[s].first>=i&&hashtag[s].first<=i+desiredRows-1&&hashtag[s].second>=k&&hashtag[s].second<=k+desiredRows-1)
           {
               negative=true;
               break;
           }
       }
       if(!negative)
       {
           found++;
       }
    }
}
cout<<found;
}

