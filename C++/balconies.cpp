#include<iostream>
using namespace std;
    int n;
    int arr[23];
int main(int argc, char argv[])
{
    cin>>n;    int sumArr=0;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        arr[i+1]=num;
        sumArr+=num;
    }
    arr[0]=arr[n];
    arr[n+1]=arr[0];
    int damageTaken=0;
    while(true)
    {
        int indexMiddle=-1;
        int sumBiggest=-1;
        for(int i=1;i<=n;i++)
        {
            if(arr[i]+arr[i+1]+arr[i-1]>sumBiggest)
            {
                sumBiggest=arr[i]+arr[i+1]+arr[i-1];
                indexMiddle=i;
            }
        }
          if(indexMiddle==1)
            {
                arr[0]=0;arr[1]=0;arr[2]=0;arr[n]=0;
                arr[n+1]=0;
            }
        else if(indexMiddle==n)
            {
                arr[n]=0;arr[n+1]=0;arr[0]=0;arr[n-1]=0;
            }
            else{
                arr[indexMiddle]=0;arr[indexMiddle+1]=0;arr[indexMiddle-1]=0;
            }
        sumArr-=sumBiggest;
        damageTaken+=sumArr;
        if(sumBiggest==0)
        {
            break;
        }
    }
    cout<<damageTaken;
}
