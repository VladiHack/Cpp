#include <bits/stdc++.h>
using namespace std;
bool tacos[1000000];
int main()
{
    freopen("prefmex.in","r",stdin);
    freopen("prefmex.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(tacos,false,sizeof(tacos));
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
     cin>>arr[i];
    }
    int minLast=0;
    for(int i=0;i<n;i++)
    {
        tacos[arr[i]]=true;
        while(tacos[minLast]==true)
        {
            minLast+=1;
        }
        cout<<minLast<<" ";
    }

}
