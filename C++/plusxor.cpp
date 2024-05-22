#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
long long int a;
long long int b;
cin>>a>>b;
long long int x=0;
for(long long int i=0;i<=a/2;i++)
{
    x=(a-i)^i;
    if(x==b)
    {
        x=a-i;
        cout<<i<<" "<<x;
        return 0;
    }
    if(x<b)
    {
        break;
    }
}
cout<<"-1";
}
