#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> met;
int counter=0;
int main()
{
int n;
cin>>n;
for(int i=0;i<n;i++)
{
    string name1;string name2;string name3;
    cin>>name1>>name2>>name3;
    string smallest=name1;string biggest=name2;
    string avg=name3;
    if(smallest>name2)
    {
        avg=smallest;
        smallest=name2;
    }
    if(smallest>name3)
    {
        avg=smallest;
        smallest=name3;
    }
    if(biggest<name1)
    {
        biggest=name1;
    }
    if(biggest<name3)
    {
        biggest=name3;
    }
    string res=smallest;
    res+=" ";
    res+=avg;
    res+=" ";
    res+=biggest;
    met[res]++;
    if(counter<met[res])
    {
        counter=met[res];
    }
}
int x;
cin>>x;
cout<<counter;
}
