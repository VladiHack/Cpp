#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++)
    {
        pair<int,int> newPair;
        int num1;int num2;
        cin>>num2>>num1;
        newPair.first=num1;
        newPair.second=num2;
        vec.push_back(newPair);
    }
    int included=0;
    sort(vec.begin(),vec.end());
    int lastEnd=0;
    for(int i=0;i<n;i++)
    {
       if(lastEnd<vec[i].second)
       {
          lastEnd=vec[i].first;
          included++;
       }
    }
    cout<<included;

}
