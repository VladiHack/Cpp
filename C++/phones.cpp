#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int m;
    cin>>n>>m;
    priority_queue<double> phones;
    for(int i=0;i<n;i++)
    {
        double num;
        cin>>num;
        phones.push(num);
    }
    priority_queue<double> fakturi;
    for(int i=0;i<m;i++)
    {
        double num;
        cin>>num;
        fakturi.push(num);
    }
    while(phones.size()!=0)
    {
        if(fakturi.size()==0)
        {
              cout<<fixed<<setprecision(2)<<phones.top()<<" ";
            phones.pop();
            continue;
        }
        if(phones.top()>fakturi.top())
        {
              cout<< fixed << setprecision(2)<<phones.top()<<" ";
            phones.pop();
            continue;
        }
        if(phones.top()==fakturi.top())
        {
            phones.pop();
            fakturi.pop();
            continue;
        }
        if(phones.top()<fakturi.top())
        {
            fakturi.pop();
            continue;
        }
    }

}
