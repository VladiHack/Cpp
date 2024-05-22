#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void findCombos(int pos,int sum,int arr[],int sizeArr,string msg);
int result=0;
vector<string> metStrings;
int main()
{
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
    int num;
    cin>>num;
    arr[i]=num%2;
}
findCombos(0,0,arr,n,"");
cout<<result;


}
void findCombos(int pos,int sum,int arr[],int sizeArr,string msg)
{
    if(sum>0)
    {
          if (!count(metStrings.begin(), metStrings.end(), msg))
          {
              result++;
            cout<<msg;
            cout<<"\n";
           metStrings.push_back(msg);
          }

    }
    if(pos==sizeArr)
    {
        return;
    }
    for(int i=pos;i<sizeArr;i++)
    {
        pos++;
        sum+=arr[i];
        string toAdd=to_string(arr[i]);
          msg+=toAdd;
        msg+=" ";

        findCombos(pos,sum,arr,sizeArr,msg);
    }
}
