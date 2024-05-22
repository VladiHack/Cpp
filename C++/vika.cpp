#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
for(int l=0;l<n;l++)
{
 int rows;int cols;
 int vika=0;
 char arr[rows][cols];

     for(int i=0;i<rows;i++)
     {
         for(int s=0;s<cols;s++)
         {
             cin>>arr[i][s];
         }
     }
     for(int i=0;i<cols;i++)
    {
        for(int k=0;k<rows;k++)
        {
            if(vika==0&&arr[k][i]=='v')
            {
                vika++;
                break;
            }
            else if(vika==1&&arr[k][i]=='i')
            {
                vika++;
                break;
            }
            else if(vika==2&&arr[k][i]=='k')
            {
                vika++;
                break;
            }
            else if(vika==3&&arr[k][i]=='a')
            {
                vika++;
                break;
            }
        }
        if(vika==4)
        {
            break;
        }
    }
    if(vika==4)
    {
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }


}


}
