#include <iostream>
using namespace std;

int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int t;
cin>>t;
for(int i=0;i<t;i++)
{
long long int n;long long int k;long long int x;
long long int sumAll=0;
    cin>>n>>k>>x;
    sumAll=0;long long int sumMin=0;
    sumMin=k*(1+k)/2;
    sumAll=k*(n+n-k+1)/2;
    cout<<sumAll<<" "<<sumMin;
    if(sumAll<x||sumMin>x)
    {
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
}

}
