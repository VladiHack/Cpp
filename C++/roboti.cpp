#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;int n1;int n2;
    long long int fin=-1;
    int tFin=0;
    cin>>T>>n1;
    vector<int> Ak;vector<int> Bk;
    for(int i=0;i<n1;i++)
    {
       int num1;int num2;
       cin>>num1>>num2;
       Ak.push_back(num1);
       Bk.push_back(num2);
    }
    cin>>n2;
    vector<int> Ck;vector<int> Dk;
    for(int i=0;i<n2;i++)
    {
         int num1;int num2;
       cin>>num1>>num2;
       Ck.push_back(num1);
       Dk.push_back(num2);
    }
    int l=1;int r=T-1;
    while(l<=r)
    {
        int t1=l+(r-l)/2;
      long long int robots=0;
        for(int i=0;i<n1;i++)
        {
           if(t1>=Ak[i])
           {
               robots+=(t1-Ak[i])/Bk[i]+1;
           }
        }
        int t2=T-t1;
        long long int robots2=0;
        for(int i=0;i<n2;i++)
        {
            if(t2>=Ck[i])
            {
                robots2+=(t2-Ck[i])/Dk[i]+1;
            }
        }
        int smallerRob=min(robots,robots2);
        if(smallerRob>=fin)
        {
          fin=smallerRob;
          tFin=t1;
        }
        if(smallerRob==robots)
        {
            l=t1+1;

        }
        else
        {
            r=t1-1;
        }
    }
    cout<<tFin;
}
