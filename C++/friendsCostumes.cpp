
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n+1];

    int people[n][2];
    for(int i=0;i<n;i++)
    {
        int left;
        int right;
        cin>>left;
        cin>>right;
        for(int k=left;k<=right;k++)
        {
            arr[k]++;
        }
        people[i][0]=left;
        people[i][1]=right;
    }

}




