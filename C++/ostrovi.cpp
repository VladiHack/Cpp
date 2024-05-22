    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    int islandCount=0;
    int arr[101][101];
    bool checkedPos[101][101];
    int rows;int cols;
    bool isSemiIsland=false;
    void CheckIsland(int row,int col)
    {
        if(arr[row][col]==1&&checkedPos[row][col]==false&&row!=-1&&row!=rows&&col!=-1&&col!=cols)
        {
            checkedPos[row][col]=true;
            if(row==0||row==rows-1||col==0||col==cols-1)
            {
                isSemiIsland=true;
            }
            CheckIsland(row+1,col);
            CheckIsland(row+1,col+1);
            CheckIsland(row+1,col-1);
            CheckIsland(row,col+1);
            CheckIsland(row,col-1);
            CheckIsland(row-1,col);
            CheckIsland(row-1,col+1);
            CheckIsland(row-1,col-1);

        }
    }
    int main()
    {
        cin>>rows>>cols;
        memset(checkedPos,false,sizeof(checkedPos));
        for(int i=0;i<rows;i++)
        {
            for(int k=0;k<cols;k++)
            {
                cin>>arr[i][k];
            }
        }
        for(int i=0;i<rows;i++)
        {
            for(int k=0;k<cols;k++)
            {
                isSemiIsland=false;
                if(arr[i][k]==1)
                {
                    CheckIsland(i,k);
                    if(isSemiIsland==false)
                    {
                        islandCount++;
                    }
                }
            }
        }
        cout<<islandCount;
    }
