
#include <iostream>
#include <bits/stdc++.h>
int result="";
using namespace std;
int main()
{
  int n;
  int k;
  cin>>n>>k;
  vector<int> vec;
  for(int i=0;i<n;i++)
  {
      int num;
      cin>>num;
      vec.push_back(num);
  }


}
void PrintResults(vector<int> vec,int k,string path)
{
    if(vec.size<2)
    {
        if(vec[0]==k)
        {
            result="YES\n";
            result+=path;
        }
        else{
            result="NO";
        }
        return;
    }
    int val1;
    int val2;
    val1=vec[0]&vec[1];
    val2=vec[0]|vec[1];
    vec.erase (vec.begin(),vec.begin()+2);
    PrintResults()
}

