#include <iostream>
using namespace std;
int counter;
void Recursion(int arr[],int pos)
{
   if(pos==0)
   {
       for(int i=1;i<=100;i++)
       {
           int copyArr[counter];
           copyArr=arr;
           copyArr[pos]=i;
           Recursion(copyArr,pos+1);
       }
   }
   if(pos==1)
   {
       for(int i=arr[pos-1]+1;i<=100;i++)
       {
           int[] copyArr=arr;
           copyArr[pos]=i;
       }
   }
}
int main()
{
int tests;
cin>>tests;
for(int i=0;i<tests;i++)
{
    cin>>counter;
}

}
