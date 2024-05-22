 #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int n;int k;
cin>>n>>k;
int countNew=0;
int saved[n];
int sums[n];
memset(saved,-1,sizeof(saved));
memset(sums,0,sizeof(sums));
for(int i=0;i<k;i++)
{
int left;int right;
cin>>left>>right;
int countToKeep=0;
    if(saved[left]==-1&&saved[right]==-1)
    {
        saved[left]=countNew;saved[right]=countNew;
        sums[countNew]=2;
        countNew++;
    }
    else if(saved[left]!=-1&&saved[right]==-1)
    {
        countToKeep=saved[left];
        saved[right]=countToKeep;
        sums[saved[right]]++;
    }
    else if(saved[right]!=-1&&saved[left]==-1)
    {
        countToKeep=saved[right];
        saved[left]=countToKeep;
        sums[saved[right]]++;
    }
    else
    {
        countToKeep=saved[right];
        int countDelete=saved[left];
       for(int k=0;k<n;k++)
       {
           if(saved[k]==countDelete)
           {
               sums[countDelete]--;
               sums[countToKeep]++;
               saved[k]=countToKeep;
           }
       }
    }
}

}
