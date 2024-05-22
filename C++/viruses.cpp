 #include <iostream>
        #include <bits/stdc++.h>
        using namespace std;
        int maxSteps=0;
        int arr[3000][3000];
        int rows;int cols;
        int main()
        {
          cin>>rows>>cols;
          for(int i=0;i<rows;i++)
          {
              for(int k=0;k<cols;k++)
              {
                  arr[i][k]=rows+cols;
              }
          }
          int k;
          cin>>k;
          for(int i=0;i<k;i++)
          {
              int row;int col;
              cin>>row>>col;
              row--;col--;
           for(int k=0;k<rows;k++)
           {
               for(int j=0;j<cols;j++)
               {
                   arr[k][j]=min(arr[k][j],abs(j-col)+abs(k-row));
               }
           }
          }
          for(int i=0;i<rows;i++)
          {
              for(int k=0;k<cols;k++)
              {
                  maxSteps=max(arr[i][k],maxSteps);
              }
          }


          cout<<maxSteps;
          }
