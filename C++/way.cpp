#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int res=0;
 vector<tuple<int,int,int>> arr;
void Recursion(int pos,int price,int n)
{
    if(pos==n)
    {
        if(res==0||price<res)
        {
          res=price;
        }
        return;
    }
    for(int i=0;i<arr.size();i++)
    {
        if(get<0>(arr[i])==pos)
        {
            Recursion(get<1>(arr[i]),price+get<2>(arr[i]),n);
        }
    }
}
int main(int argc, char *argv[])
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;int m;
        cin>>n>>m;
        res=0;
        arr.clear();
        for(int s=0;s<m;s++)
        {
            int c1;int c2;int d;
            cin>>c1>>c2>>d;
            tuple<int,int,int> val;
            val=make_tuple(c1,c2,d);
            arr.push_back(val);
        }
        Recursion(1,0,n);
        cout<<res<<"\n";

    }
}
