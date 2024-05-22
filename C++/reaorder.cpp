#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int sum;
int indexLast;
int n;int q;int a;
void Replace(int index,long long int sumByFar,int arr[])
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"INDEX "<<index<<" SUMBYFAR "<<sumByFar<<"\n";
    if(sumByFar>=sum)
    {
        return;
    }
   if(index==-1)
   {
       sum=sumByFar;
       return;
   }
   if(index!=0&&index>=indexLast)
   {
       int temp=arr[index];
       arr[index]=arr[index-1];
       arr[index-1]=temp;
       Replace(index-1,sumByFar+arr[index]+arr[index-1],arr);
       arr[index-1]=arr[index];
       arr[index]=temp;
   }
   if(index>=indexLast)
   {
        Replace(index-1,sumByFar,arr);
   }
   else
   {
    Replace(index-1,sumByFar+arr[index]*a,arr);
   }

}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>n>>q>>a;
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
for(int i=0;i<q;i++)
{
    cin>>indexLast;
    sum=LLONG_MAX;
    Replace(n-1,0,arr);
    cout<<sum<<"\n";
}
}
