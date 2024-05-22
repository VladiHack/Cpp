#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
int arr[n][3];
int smallest[n]{0};
for(int i=0;i<n;i++)
{
    for(int k=0;k<3;k++)
    {
        cin>>arr[i][k];
    }
}
smallest[0]=arr[0][0];
if(n==1)
{
    cout<<smallest[0];
    return 0;
}
smallest[1]=min(arr[0][0]+arr[1][0],arr[0][1]);
 if(n==2)
{
    cout<<smallest[1];
    return 0;
}
smallest[2]=min(min(smallest[0]+arr[1][1],smallest[1]+arr[1][0]),arr[0][2]);
if(n==3)
{
cout<<smallest[2];
return 0;
}
for(int i=3;i<n-1;i++)
{
smallest[2]=min(min(smallest[0]+arr[1][1],smallest[1]+arr[1][0]),arr[0][2]);
}
for(int i=0;i<n-1;i++)
{
    cout<<smallest[i]<<"\n";
}
}

