#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string reader;
        cin>>reader;
        long long int sumAll=0;
        long long int res=0;
        for(int s=0;s<reader.size();s++)
        {
           sumAll+=(reader[s]-'0');
        }
        for(int s=0;s<reader.size();s++)
        {
            res+=sumAll-(reader[s]-'0');
        }
        cout<<res<<"\n";
    }
}
