#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int MOD;
int fastPow(int num, int power) {
    int ret = 1;
    for (; power > 0; power >>= 1) {
        if (power & 1)
            ret = ((long long)ret * num) % MOD;
        num = ((long long)num * num) % MOD;
    }
    return ret;
}
int main()
{
int t;
cin>>t;
for(int i=0;i<t;i++)
{
    int n;int p;
    cin>>n>>p>>MOD;
    cout<<fastPow(n,p)<<"\n";
}
string zero;
cin>>zero;
}
