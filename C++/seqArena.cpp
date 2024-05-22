#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int upToN;
int sum;
int countMet=0;
void findPaths(int currentSum,int steps[270]);
int main(int argc, char *argv[])
{
    cin>>sum;
    cin>>upToN;
}
void findPaths(int currentSum,int steps[270])
{
    if(currentSum>=sum)
    {
        if(currentSum==sum)
        {

        }
        return;
    }
    for(int i=upToN;i>=1;i--)
    {

        findPaths(currentSum+i,msg);
    }
}
