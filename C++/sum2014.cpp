 #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
        double power(double num,int n);
    int main()
    {
      int n;
      cin>>n;
      int arr[n];
      for(int i=0;i<n;i++)
      {
          cin>>arr[i];
      }
      int dp[n];
      memset(dp,0,sizeof(dp));
      dp[0]=arr[0];
      int maxVal=dp[0];
      for(int i=0;i<n;i++)
      {
          dp[i]=max(dp[i-1]+arr[i],arr[i]);
          maxVal=max(maxVal,dp[i]);
      }
      cout<<maxVal;
    }
