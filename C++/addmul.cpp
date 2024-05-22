#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> nums;
    nums.push_back(1);
    int steps=0;
    unordered_map<int,bool> met;
    met[1]=true;
    while(true)
    {
        if(met[n])
        {
            cout<<steps;
            return 0;
        }
        steps++;
                    int fixSize=nums.size();
        for(int i=0;i<fixSize;i++)
        {
            for(int k=i;k<fixSize;k++)
            {
                if(met[nums[i]+nums[k]]==false)
                {
                    nums.push_back(nums[i]+nums[k]);
                    met[nums[i]+nums[k]]=true;
                }
                if(met[nums[i]*nums[k]]==false)
                {
                    nums.push_back(nums[i]*nums[k]);
                    met[nums[i]*nums[k]]=true;
                }
                if(met[n])
                {
                    cout<<steps;
                    return 0;
                }
            }
        }
    }
}
