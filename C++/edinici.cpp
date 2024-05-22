#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;
for(int i=0;i<t;i++)
{
    int n;
    cin>>n;
    string res="";
    int adder=1;
    for(int i=0;i<n;i++)
    {
        int digit=adder%10;
        res+=to_string(digit);
        adder++;
    }
}
}
