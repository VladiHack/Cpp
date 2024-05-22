#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int lowestReduced=-1;
unordered_map<int,long long int> cheapest;
void Recursion(vector<long long int> vec,long long int reduced,int pos)
{
    if(reduced>=lowestReduced&&lowestReduced!=-1)
    {
        return;
    }
    if(cheapest[pos]<=reduced&&cheapest[pos]!=0)
    {
        return;
    }
    cheapest[pos]=reduced;
    if(vec.size()==1)
    {
        lowestReduced=reduced;
        return;
    }
    for(int i=1;i<vec.size();i++)
    {
        if(cheapest[pos+1]>reduced+max(vec[i],vec[i-1])&&cheapest[pos+1]!=0)
        {
             vector<long long int> copyVec=vec;
        if(vec[i]<vec[i-1])
        {
          copyVec.erase(copyVec.begin()+i);
          Recursion(copyVec,reduced+vec[i-1],pos+1);
        }
        else
        {
          copyVec.erase(copyVec.begin()+i-1);
          Recursion(copyVec,reduced+vec[i],pos+1);
        }
        }

    }
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
vector<long long int> vec;
for(int i=0;i<n;i++)
{
    long long int num;
    cin>>num;
    vec.push_back(num);
}
Recursion(vec,0,0);
cout<<lowestReduced;
}
