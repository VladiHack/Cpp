#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char argv[])
{
int friends;
cin>>friends;
int result[friends]{0};
int arr[friends]{0};
int shirtForEachFriend[friends][friends];
  fill((int*)shirtForEachFriend,(int*)shirtForEachFriend+sizeof(shirtForEachFriend)/sizeof(int),0);

for(int i=0;i<friends;i++)
{
    int left;int right;
    cin>>left>>right;
    left--; right--;
    for(int k=left;k<=right;k++)
    {
        shirtForEachFriend[i][k]++;
        arr[k]++;
    }
}
while(true)
{
    int index=-1;
for(int i=0;i<friends;i++)
{
    if(arr[i]!=0)
    {
         if(index==-1)
   {
       index=i;
   }
   else if(arr[i]<arr[index])
   {
       index=i;
   }
    }

}
if(index==-1)
{
    cout<<"YES\n";
    for(int l=0;l<friends;l++)
    {
        cout<<result[l]<<" ";
    }
    return 1;
}
cout<<"index:"<<index<<"\n";
int shortestFriendIndex=-1;
for(int i=0;i<friends;i++)
{
    if(arr[i]!=0)
    {
           if(shirtForEachFriend[i][index]>0)
    {
        if(shortestFriendIndex==-1)
        {
            shortestFriendIndex=i;
        }
        else if(arr[i]<arr[shortestFriendIndex])
        {
            shortestFriendIndex=i;
        }
    }
    }

}
if(shortestFriendIndex==-1)
{
  cout<<"NO";
  return -1;
}
else
{
    result[index]=shortestFriendIndex;
    arr[shortestFriendIndex]=0;
}
}



/*
for(int i=0;i<friends;i++)
{
    for(int k=0;k<friends;k++)
    {
        cout<<shirtForEachFriend[i][k]<<" ";

    }
    cout<<"\n";
}
*/
}
