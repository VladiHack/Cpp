#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unordered_map<int,unordered_map<int,int>> timesMet;
unordered_map<int,unordered_map<int,bool>> metAtAll;
int main()
{
  freopen("intersection.in","r",stdin);
    freopen("intersection.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<double> keepK;
    vector<double> keepN;
    for(int i=0;i<n;i++)
    {
        int x1;int y1;int x2;int y2;
        cin>>x1>>y1>>x2>>y2;
        double k=(y2-y1)*1.0/(x2-x1);
        double n=((y1*x2)-(x1*y2))*1.0/(x2-x1);
        keepK.push_back(k);
        keepN.push_back(n);
    }
    for(int i=0;i<n;i++)
    {
        for(int s=i+1;s<n;s++)
        {
            int x1=(keepN[s]-keepN[i])/(keepK[i]-keepK[s]);
            int y1=(keepK[s]*keepK[i]-keepN[i]*keepK[s])/(keepK[i]-keepK[s]);
            if(metAtAll[x1][y1])
            {
                timesMet[x1][y1]++;
                if(timesMet[x1][y1]==n/4)
                {
                    cout<<
                }
            }

        }
    }
}
