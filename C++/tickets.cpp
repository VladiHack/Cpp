#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int people;
    cin>>people;
    int arr[people][3];
    for(int i=0;i<people;i++)
    {
        for(int k=0;k<3;k++)
        {
            cin>>arr[i][k];
        }
    }
    int cheapest=0;
    int currentRow=0;
    while(currentRow<people)
    {
        int currentSmallest=10000000;int nextRow=currentRow;
        if(people-currentRow>2)
        {
            nextRow=currentRow+3;
            currentSmallest=arr[currentRow][2];
            if(arr[currentRow][1]+arr[currentRow+1][0]<currentSmallest)
            {
                currentSmallest=arr[currentRow+1][0]+arr[currentRow][1];
            }
            if(arr[currentRow][0]+arr[currentRow+1][1]<currentSmallest)
            {
                currentSmallest=arr[currentRow+1][1]+arr[currentRow][0];
            }
            if(arr[currentRow][0]+arr[currentRow+1][0]+arr[currentRow+2][0]<currentSmallest)
            {
                currentSmallest=arr[currentRow][0]+arr[currentRow+1][0]+arr[currentRow+2][0];
            }
        }
        else if(people-currentRow==2)
        {
            nextRow=currentRow+2;
            currentSmallest=arr[currentRow][1];
            if(arr[currentRow][0]+arr[currentRow+1][0]<currentSmallest)
            {
                currentSmallest=arr[currentRow][0]+arr[currentRow+1][0];
            }
        }
        else
        {
          currentSmallest=arr[currentRow][0];
          nextRow=currentRow+1;
        }
       currentRow=nextRow;
       cheapest+=currentSmallest;
    }
    cout<<cheapest;
}


