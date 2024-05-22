#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
int n;int k;
cin>>n>>k;
vector<int> arr;
for(int i=0;i<n;i++)
{
    int num;
    cin>>num;
    arr.push_back(num);
}
while(arr.size()>=k)
{
    int sumBiggest=-2;
    int indexStart=-1;int indexEnd=-1;
    for(int i=0;i<arr.size();i++)
    {
            int sum=0;
            if(i+k-1<arr.size())
            {
                for(int s=i+1;s<i+k-1;s++)
            {
                sum+=arr[s];
            }
            sum-=arr[i]*arr[i+k-1];
            if(sum>sumBiggest)
            {
                sumBiggest=sum;
                indexStart=i;indexEnd=arr[i+k-1];
            }
        }
    }
    cout<<sumBiggest<<"\n"<<indexStart+1<<" "<<indexEnd+1<<"\n";
    arr.erase(arr.begin()+indexStart,arr.begin()+indexEnd);
}

}
