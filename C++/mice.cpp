    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    unordered_map<int,unordered_map<int,int>> arr;
    unordered_map<int,unordered_map<int,bool>> met;
    int maxMice=0;
    int main()
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int row;int col;int mice;
            cin>>row>>col>>mice;
            if(met[row][col+1]==true)
            {
               arr[row][col+1]+=mice;
            }
            else{
                met[row][col+1]=true;
                arr[row][col+1]=mice;
            }
            if(met[row][col-1]==true)
            {
                arr[row][col-1]+=mice;
            }
            else{
                met[row][col-1]=true;
                arr[row][col-1]=mice;
            }
            if(met[row-1][col]==true)
            {
                arr[row-1][col]+=mice;
            }
            else{
                met[row-1][col]=true;
                arr[row-1][col]=mice;
            }
            if(met[row+1][col])
            {
                arr[row+1][col]+=mice;
            }
            else{
                met[row+1][col]=true;
                arr[row+1][col]=mice;
            }
            if(arr[row][col+1]>maxMice)
            {
                maxMice=arr[row][col+1];
            }
            if(arr[row][col-1]>maxMice)
            {
                maxMice=arr[row][col-1];
            }
            if(arr[row-1][col]>maxMice)
            {
                maxMice=arr[row-1][col];
            }
            if(arr[row+1][col]>maxMice)
            {
                maxMice=arr[row+1][col];
            }
        }
        cout<<maxMice;
    }
