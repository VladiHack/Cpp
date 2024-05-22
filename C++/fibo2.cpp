#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
long long int zapis;long long int n;
cin>>zapis>>n;
string first;string second;
cin>>first>>second;
for(int i=first.size()-1;i>=0;i--)
{
    if(first[i]=='A')
}
long long int a=0;
long long int b=0;
for(int i=3;i<=n;i++)
{
    b+=a;
    a=b-a;
}
b/=zapis;
int keep=b%zapis;
cout<<b;
}
