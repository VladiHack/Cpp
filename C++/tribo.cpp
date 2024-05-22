    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
     int p;
     bool met[1001];
     memset(met,false,sizeof(met));
     cin>>p;
     int first=0;
     int second=0;
     int third=1;
     int res=3;
     vector<vector<int>> arr;
     while(true)
     {
         res++;
         int temp=third;
         third=(first+second+third)%p;
         first=second;
         second=temp;
         for(int i=0;i<arr.size();i++)
         {
             if(arr[i][0]==first)
             {
                 if(arr[i][1]==second)
                 {
                     if(arr[i][2]==third)
                     {
                         cout<<res-2;
                         return 0;
                     }
                 }
                 else if(arr[i][1]==third)
                 {
                     if(arr[i][2]==second)
                     {
                         cout<<res-2;
                         return 0;
                     }
                 }
             }
             else if(arr[i][0]==second)
             {
                 if(arr[i][1]==first)
                 {
                     if(arr[i][2]==third)
                     {
                         cout<<res-2;
                         return 0;
                     }
                 }
                 else if(arr[i][1]==third)
                 {
                     if(arr[i][2]==first)
                     {
                         cout<<res-2;
                         return 0;
                     }
                 }
             }
             else if(arr[i][0]==third)
             {
                 if(arr[i][1]==first)
                 {
                     if(arr[i][2]==second)
                     {
                         cout<<res-2;
                         return 0;
                     }
                 }
                 else if(arr[i][1]==second)
                 {
                     if(arr[i][2]==first)
                     {
                         cout<<res-2;
                         return 0;
                     }
                 }
             }
         }
         vector<int> newVec;
         newVec.push_back(first);
         newVec.push_back(second);
         newVec.push_back(third);
         arr.push_back(newVec);
     }
    }
