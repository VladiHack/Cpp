#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{

const int N = 10000000;
vector<int> lp(N+1);
vector<int> pr;
vector<int> countLps(N+1);

for (int i=2; i <= N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
    }
    for (int j = 0; i * pr[j] <= N; ++j) {
        lp[i * pr[j]] = pr[j];
        countLps[lp[i]]++;
        if (pr[j] == lp[i]) {
            break;
        }
    }
}
for(int i=2;i<=N;i++)
{
    cout<<countLps[i]<<" "<<i<<"\n";
}
}
