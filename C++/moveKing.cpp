#include<iostream>
using namespace std;
int main(int argc, char argv[])
{
   int col;
   int row;
   cin>>col>>row;
   col--;row--;
   int arr[8][8];
   row=7-row;
    fill((int*)arr,(int*)arr+sizeof(arr)/sizeof(int),0);
   arr[row][col]=1;
   row--;
   while(row>=0)
   {
       for(int k=0;k<8;k++)
       {
           if(k!=0&&k!=7)
           {

               arr[row][k]+=arr[row+1][k+1]+arr[row+1][k-1];

           }
           else if(k==0)
           {
                   arr[row][k]+=arr[row+1][k+1];
           }
           else if(k==7)
           {
               arr[row][k]+=arr[row+1][k-1];
           }

       }
       row--;
   }
   int paths=0;
   for(int i=0;i<8;i++)
   {
           paths+=arr[0][i];
    }
   cout<<paths;
}
