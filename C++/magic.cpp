#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int variations=0;
void CheckVar(vector<int> arr)
{
    int sum=arr[0]+arr[1]+arr[2];
       if(arr[3]+arr[4]+arr[5]==sum&&arr[6]+arr[7]+arr[8]==sum&&arr[0]+arr[3]+arr[6]==sum&&arr[1]+arr[4]+arr[7]==sum&&arr[2]+arr[5]+arr[8]==sum&&arr[0]+arr[4]+arr[8]==sum&&arr[6]+arr[4]+arr[2]==sum)
       {
           variations++;
       }
}
int main(int argc, char argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr;
    for(int i=0;i<9;i++)
    {
        int num;
        cin>>num;
        arr.push_back(num);
    }
    CheckVar(arr);
    while(next_permutation(arr.begin(),arr.end()))
    {
       CheckVar(arr);
    }
    cout<<variations;

}
