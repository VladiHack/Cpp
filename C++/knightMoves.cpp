#include<iostream>
using namespace std;
int n;
int m;
int main(int argc, char argv[])
{
   cin>>n>>m;
   int arr[n][m];
   arr[0][0]=1;
   fill((int*)arr,(int*)arr+sizeof(arr)/sizeof(int),0);

}
void FindPaths(int x,int y,int arr[])
{
    if(x==n-1&&y==m-1)
    {
        return;
    }
    if(x+2<n&&y+2<m)
    {
        if(arr[x+2][y+2]!=0)
        {
            return;
        }
        else
        {
        arr[x+2][y+2]=arr[x][y];
        FindPaths(x+2,y+2,arr);
        }

    }
    if(x+1<n&&y+1<m)
    {
        if(arr[x+1][y+1]!=0)
        {
            return;
        }
        else
        {

        arr[x+1][y+1]=arr[x][y];
        }

    }
}




