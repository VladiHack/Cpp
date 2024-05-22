#include <iostream>
using namespace std;
int k; int l=0; bool doesntWork=false;
void Recursion(int player,int position,int tryAdd)
{
    if(doesntWork)
    {
        return;
    }
   if(k-position<=tryAdd)
   {
       if(player==1)
       {
           doesntWork=true;
       }

   }
   for(int i=1;i<=tryAdd;i++)
   {
       if(position+i>k)
       {
           break;
       }
       if(player==1)
       {
           Recursion(2,position+i,tryAdd);
       }
       else{
        Recursion(1,position+i,tryAdd);
       }
   }
}
int main()
{
    cin>>k;
    for(int s=2;s<k;s++)
    {
        doesntWork=false;
        Recursion(1,0,s);
        if(!doesntWork)
        {
            l=s;
            break;
        }
    }
    cout<<l;
}

