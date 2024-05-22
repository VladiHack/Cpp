#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxNum;int maxSize;int MaxSum;
int res=0;
void Recursion(int currentSize,int sum)
{
    if(currentSize==maxSize)
    {
        res++;
        return;
    }
    for(int i=0;i<maxNum;i++)
    {
        if(sum+i>=MaxSum)
        {
            break;
        }
        Recursion(currentSize+1,sum+i);
    }
}
int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>maxNum>>maxSize>>MaxSum;
    Recursion(0,0);
    cout<<res;
}


