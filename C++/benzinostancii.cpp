#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
int V;
int arr[18][18];

int main()
{
     int tests;
     cin>>tests;
     for(int t=0;t<tests;t++)
     {
       cin>>V;
       memset(arr,0,sizeof(arr));
        for(int i=0;i<V;i++)
        {
            for(int s=0;s<V-i;s++)
            {
                int num;
                cin>>num;
                arr[i][ s + i + 1] = num;
                arr[s + i + 1][i] = num;
            }

     }

}
