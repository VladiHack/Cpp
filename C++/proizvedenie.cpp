#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int value=0;
    vector<long long int> arr;
while(cin>>value)
{
    arr.push_back(value);
}
long long int maxVal=0;
string res="";
for(int i=0;i<arr.size();i++)
{
    for(int k=i+1;k<arr.size();k++)
    {
        if(arr[k]>arr[i])
        {
            for(int j=k+1;j<arr.size();j++)
            {
                if(arr[j]>arr[k])
                {
                    if(maxVal<arr[i]*arr[k]*arr[j])
                    {
                     maxVal=arr[i]*arr[k]*arr[j];
                     res=to_string(i+1);
                     res+=" ";
                     res+=to_string(k+1);
                     res+=" ";
                     res+=to_string(j+1);
                    }
                }
            }
        }
    }
}
cout<<maxVal<<"\n"<<res;
return 0;
}
