#include<iostream>
using namespace std;
bool different[2000002]{false};
long long int result=0;
long long int steps=15;
int getSize=0;
void findPaths(int currentSum,int arr[]);
int main(int argc, char argv[])
{
    cin>>getSize;
    int arr[getSize];
    for(int i=0;i<getSize;i++)
    {
        cin>>arr[i];
    }
    findPaths(0,arr);
    cout<<result;
}
void findPaths(int currentSum,int arr[])
{
     if(steps==0)
     {
         return;
     }
     if(currentSum<0)
    {
        int pos=currentSum*-1;
        pos+=1000000;
        if(different[pos]==false)
        {
            different[pos]=true;
            result++;
        }
    }
    else if(different[currentSum]==false)
    {
        if(currentSum>0)
        {
            result++;
            different[currentSum]=true;
        }
        else if(arr[0]==0||result!=0)
        {
            result++;
            different[currentSum]=true;
        }
    }
    for(int i=0;i<getSize;i++)
    {
        steps--;
       findPaths(currentSum+arr[i],arr);
    }
}
