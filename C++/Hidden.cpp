#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int arr[100];int num;
int cheapest[100];
void Cheapest();
int main()
{
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    cheapest[0]=arr[0];
    cheapest[1]=arr[1];
    Cheapest();
    cout<<cheapest[num-1];
}
void Cheapest()
{
   for(int i=2;i<num;i++)
   {
       cheapest[i]=min(cheapest[i-1],cheapest[i-2])+arr[i];
   }
}
