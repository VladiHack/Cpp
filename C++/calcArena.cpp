 #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        int people;int couples;
        cin>>people>>couples;
        int arr[people];
        memset(arr,-1,sizeof(arr));
        int counter=0;
        int dp[couples];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<couples;i++)
        {
            int first;int second;
            cin>>first>>second;
            if(arr[first]!=-1)
            {
                arr[second]=arr[first];
                dp[arr[second]]++;
            }
            else if(arr[second]!=-1)
            {
                arr[first]=arr[second];
                dp[arr[second]]++;
            }
            else
            {
                  arr[first]=counter;
                  arr[second]=counter;
                  dp[counter]=2;
                  counter++;
            }
        }
        int res=1;
        for(int i=0;i<couples;i++)
        {
            if(dp[i]==-1)
            {
                break;
            }
            cout<<dp[i]<<" ";
            res*=dp[i];
        }
        //cout<<res;
    }
