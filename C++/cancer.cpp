#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int smallestSum=2147483647;
int n;int aquariums;
void Recursion(int arr[],int index,int startIndex,int aquarium,int collectedFear)
{
    if(index==n||collectedFear>=smallestSum)
    {
        if(collectedFear<smallestSum)
        {
            smallestSum=collectedFear;
        }
        return;
    }
    if(aquariums==aquarium)
    {
        Recursion(arr,index+1,startIndex,aquarium,collectedFear);
    }
}
int main()
{
    cin>>n>>aquariums;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    Recursion(arr,0);

}
