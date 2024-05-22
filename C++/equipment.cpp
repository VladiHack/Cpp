#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int number;
  cin>>number;
  int ready[number]{false};
  vector<vector<int>> friends;
  int arr[number+1]{0};
  for(int i=1;i<=number;i++)
  {
      int left;int right;
      cin>>left>>right;
      vector<int> tshirts;
      for(int k=left;k<=right;k++)
      {
          arr[k]++;
          tshirts.push_back(k);
      }
      friends.push_back(tshirts));
  }
  //cout<<friends[0].first;
  int findSmallest=1000000;
  for(int i=1;i<=number;i++)
  {
      if(findSmallest>arr[i])
      {
          findSmallest=arr[i];
      }

  }
  if(findSmallest==0&&ready[findSmallest]==false)
  {
      cout<<"NO";
      return;
  }
  else
  {
    for(int k=0;k<number;k++)
    {
    if ((friends[k].begin(), friends[k].end(), findSmallest))
    {
            for(int l=0;l<friends[k].size();l++)
        {
            arr[friends[k][l]]--;
        }
        ready[findSmallest]=k+1;
        break;
    }
    }

  }



}

