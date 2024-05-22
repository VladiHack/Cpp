#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
  long long int n;
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  cin>>n;
  vector<pair<long long int,long long int>> arr;
  for(int i=2;i*i<=n;i++)
  {
      if(n%i==0)
      {
         pair<long long int,long long int> newPair(i,n/i);
         arr.push_back(newPair);
         cout<<i<<" "<<n/i<<"\n";
      }
  }
  for(int i=arr.size()-1;i>=0;i--)
  {
      if(arr[i].first!=arr[i].second)
      {
                cout<<arr[i].second<<" "<<arr[i].first<<"\n";
      }
  }
  cout<<n<<" "<<1;
}
