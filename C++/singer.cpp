#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
int competitions;int singers;
cin>>competitions>>singers;
bool dp[singers][competitions];
int songs=0;
memset(dp,false,sizeof(dp));
for(int i=0;i<competitions;i++)
{
    int contestants;
    cin>>contestants;
    int arr[contestants];
    for(int k=0;k<contestants;k++)
    {
        int index;
        cin>>index;
        index--;
        arr[k]=index;
    }
}
}
