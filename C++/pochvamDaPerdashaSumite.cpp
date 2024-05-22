 #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        int n;
        cin>>n;
        int arr[n];
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        if(sum<0)
        {
            sum*=-1;
            sum+=1000;
        }
        bool dp[n+1][sum+1];
        memset(dp,false,sizeof(dp));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=true;
        }
        for(int i=1;i<=sum;i++)
        {
            dp[0][i]=false;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                int conv=arr[i-1];
                if(j<conv)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-conv];
                }
            }
        }

            for(int j=0;j<=sum;j++)
            {
                cout<<dp[n][j]<<" ";
            }
            cout<<"\n";


    }
