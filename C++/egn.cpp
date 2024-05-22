#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;
for(int i=0;i<t;i++)
{
    int people;
    cin>>people;
    int counter=0;
    for(int s=0;s<people;s++)
    {
        string egn;
        cin>>egn;
        if((egn[egn.size()-2]-'0')%2==0)
        {
            counter++;
        }
    }
    cout<<counter<<"\n";
}
}
