 #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
       int n;
       cin>>n;
       for(int i=0;i<n;i++)
       {
          int maximum=0;
           int num;
           cin>>num;
           int arr[num+1];
           memset(arr,0,sizeof(arr));
           for(int k=0;k<num;k++)
           {
               int number;
               cin>>number;
               arr[number]++;
               maximum=max(maximum,arr[number]);
           }
           maximum++;
           cout<<maximum<<"\n";
       }
    }
