#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<tuple<int,int,int>> vec;
unordered_map<int,unordered_map<int,int>> met;
int longer=-1;int shortest=-1;int n;
void FindPath(int beginIndex,int endIndex,int longest,string res)
{
    if(beginIndex==endIndex)
    {
        if(longer==-1||longer<longest)
        {
            longer=longest;
        }
        if(shortest==-1||shortest>longest)
        {
            shortest=longest;
        }
        return;
    }
    for(int i=0;i<vec.size();i++)
    {
        if(get<0>(vec[i])==beginIndex)
        {
            string s=" ";
            s+=to_string(get<1>(vec[i]));s+=" ";
            if(res.find(s)!=string::npos)
            {
                continue;
            }
            else
            {
                int bigger;
                bigger=max(longest,get<2>(vec[i]));
                FindPath(get<1>(vec[i]),endIndex,bigger,res+s);
            }
        }
        if(get<1>(vec[i])==beginIndex)
        {
            string s=" ";
            s+=to_string(get<0>(vec[i]));s+=" ";
            if(res.find(s)!=string::npos)
            {
                continue;
            }
            else
            {
                int bigger;
                bigger=max(longest,get<2>(vec[i]));
                FindPath(get<0>(vec[i]),endIndex,bigger,res+s);
            }
        }
    }
}
int main()
{
cin>>n;
for(int i=0;i<n;i++)
{
    int x1;int x2;int price;
    cin>>x1>>x2>>price;
    tuple<int,int,int> triple;
    triple=make_tuple(x1,x2,price);
    vec.push_back(triple);
}
int q;
cin>>q;
int suma=0;
for(int i=0;i<q;i++)
{
    int type;int x1;int x2;
    cin>>type>>x1>>x2;
    if(type==1)
    {
                longer=-1;shortest=-1;
                string res=" ";
                res+=to_string(x1);
                res+=" ";
            FindPath(x1,x2,-1,res);
           suma+=2*longer+shortest;
    }
    else{
        continue;
    }
}
cout<<suma;
}
