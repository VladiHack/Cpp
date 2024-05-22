#include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
                int n;
                int arr[18][18];
                int minSum=INT_MAX;
                unordered_map<string,int> cheapest;
   void Recursion(int prev,int last,int length,int sum,bool used[],string collected)
   {
       if(sum>=minSum)
       {
           return;
       }
          sort(collected.begin(), collected.end());
       if(cheapest[collected]<sum&&cheapest[collected]!=0)
       {
           return;
       }
       cheapest[collected]=sum;
       if(length==n)
       {
           minSum=min(sum+arr[last][0],minSum);
       }
       else{
            for(int i=1;i<=n;i++)
            {
               if(used[i]==false)
               {
                   used[i]=true;
                   Recursion(last,i,length+1,sum+arr[last][i],used,collected+" "+to_string(i));
                   used[i]=false;
               }
            }
       }
   }
    int main()
    {
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        int t;
        cin>>t;
        for(int test=0;test<t;test++)
        {
            minSum=INT_MAX;
            cheapest.clear();
            cin>>n;
            memset(arr,0,sizeof(arr));
            for(int i=0;i<n;i++)
            {
                for(int s=i+1;s<=n;s++)
                {
                    cin>>arr[i][s];
                    arr[s][i]=arr[i][s];
                }
            }
            bool used[n+1];
            memset(used,false,sizeof(used));
            Recursion(0,0,0,0,used,"");
            cout<<minSum;
        }
    }
