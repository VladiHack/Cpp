#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;int a;int b;
long long int res=0;
long long int mod=1000000007;
int arr_a[50001];int arr_b[50001];
long long int copyRes;
void Recursion(int pos,int AorB,int streak)
{
    if(pos==n)
    {
        res++;
        return;
    }
    if(AorB==0)
    {
        if(arr_b[pos+1]!=-1)
        {
            res+=arr_b[pos+1];
        }
        else
        {
        copyRes=res;
        Recursion(pos+1,1,1);
        arr_b[pos+1]=res-copyRes;
        }
        if(streak!=a)
        {
            if(arr_a[pos+1]!=-1)
            {
                res+=arr_a[pos+1];
            }
            else{
                copyRes=res;
                Recursion(pos+1,0,streak+1);
                arr_a[pos+1]=res-copyRes;
            }
        }
    }
    else{
        Recursion(pos+1,0,1);
        if(streak!=b)
        {
            Recursion(pos+1,1,streak+1);
        }
    }
}

int main()
{
memset(arr_a,-1,sizeof(arr_a));
memset(arr_b,-1,sizeof(arr_b));
cin>>n>>a>>b;
Recursion(0,0,0);
for(int i=0;i<n;i++)
{
    cout<<arr_a[i]<<" "<<arr_b[i]<<"\n";
}
cout<<res;
}
