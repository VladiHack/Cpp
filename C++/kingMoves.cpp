
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void FindIfSumIsPossible(int sum,int arr[],int pos);
bool metSum=false;
int main()
{
   int n;
   cin>>n;
   int sequences[n];
   for(int i=0;i<n;i++)
   {
      int elements;
      cin>>elements;
      int currentSeq[elements];
      int sum=0;
      for(int k=0;k<elements;k++)
      {
          cin>>currentSeq[k];
          sum+=currentSeq[k];
      }
      if(sum%2==1)
      {
          sequences[i]=0;
      }
      else{
        //Ako e namerena sumata, to togava da zapishe 1
        FindIfSumIsPossible(sum,currentSeq,currentSeq.size());
        if(metSum==true)
        {
        sequences[i]=1;
        metSum=false;
        }
        else{
        sequences[i]=false;
        }
      }

   }
   for(int i=0;i<n;i++)
   {
       cout<<sequences[i]<<"\n";
   }
}
void FindIfSumIsPossible(int sum,int arr[],int countLength)
{   if(metSum==true)
    {
        return;
    }
    else
    {
        if(sum<=0)
        {
            if(sum==0)
            {
             metSum=true;
            }
            return;
        }
        for(int i=0;i<countLength;i++)
        {
            FindIfSumIsPossible(sum-arr[i],arr,countLength);
        }
    }

}
