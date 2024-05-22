#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
  int nums;
  cin>>nums;
  int arr[nums];
  int result=0;
  int res[1000000][3];
  int triplesFound=0;
  for(int i=0;i<nums;i++)
  {
      cin>>arr[i];
  }
  for(int i=0;i<nums-2;i++)
  {
      for(int k=i+1;k<nums-1;k++)
      {
          if(arr[i]!=arr[k])
          {
            for(int j=k+1;j<nums;j++)
              {
                if((arr[i]!=arr[j])&&(arr[j]!=arr[k]))
                {
                    if(arr[i]<arr[j]+arr[k]&&arr[j]<arr[i]+arr[k]&&arr[k]<arr[i]+arr[j])
                    {
                        bool met=false;
                        for(int l=0;l<triplesFound;l++)
                        {
                            int x=res[l][0];
                            int z=res[l][1];
                            int y=res[l][2];
                            if((x==arr[i]||x==arr[k]||x==arr[j])&&(y==arr[i]||y==arr[k]||y==arr[j])&&(z==arr[i]||z==arr[k]||z==arr[j]))
                            {
                                met=true;
                                break;
                            }
                        }
                        if(met==false)
                        {
                            res[triplesFound][0]=arr[i];
                            res[triplesFound][1]=arr[j];
                            res[triplesFound][2]=arr[k];
                            triplesFound++;
                        }
                    }

                }
              }
          }

      }
  }
  cout<<triplesFound;
}
