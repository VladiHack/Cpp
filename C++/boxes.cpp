#include<iostream>
#include <vector>
using namespace std;

int main(int argc, char argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    long long int k=1;
    while(true)
    {
        int copyN=n*n;
        int pos=0;
        while(true)
        {
            pos=(pos+k)%copyN;
            if(pos>0&&pos<=n)
            {
                k++;
                break;
            }
            copyN--;
            if(copyN==n)
            {
                cout<<k;
                return 0;
            }
        }
    }
}
