#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;
for(int i=0;i<t;i++)
{
    int n;
    cin>>n;
    int x1=-1;int x2=0;int y1=0;int y2=0;
    string arr[n][n];
    for(int k=0;k<n;k++)
    {
        for(int s=0;s<n;s++)
        {
           string symbol;
           cin>>symbol;
           arr[k][s]=symbol;
           if(symbol=="*")
           {
               if(x1==-1)
               {
                   x1=k;y1=s;
               }
               else{
                x2=k;y2=s;
               }
           }
        }
        arr[x1][y2]="*";
        arr[x2][y1]="*";
        for(int k=0;k<n;k++)
        {
            for(int s=0;s<n;s++)
            {
                cout<<arr[k][s];
            }
            cout<<"\n";
        }
    }
}


}
