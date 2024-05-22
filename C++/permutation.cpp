#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
int n;int actions;
cin>>n>>actions;
int arr[n];
int moving[n];
int temp[n];
for(int i=0;i<n;i++)
{
 arr[i]=i+1;
 cin>>moving[i];
 moving[i]--;
}
bool turnTemp=true;
while(actions!=0)
{
    actions--;
    for(int i=0;i<n;i++)
    {
        if(turnTemp)
        {
            temp[i]=arr[moving[i]];
        }
        else{
            arr[i]=temp[moving[i]];
        }
    }
    turnTemp=!turnTemp;
}
    for(int i=0;i<n;i++)
    {
        if(turnTemp==false)
        {
          cout<<temp[i]<<" ";
        }
        else{
          cout<<arr[i]<<" ";
        }
    }

}
