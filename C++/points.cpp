#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
   int pravi;
   int tochki;
   cin>>pravi;
   cin>>tochki;
   long long int resultsPositiveTo100k[100000];
   long long int resultsNegativeTo100k[100000];
   long long int resultsPositiveAbove100k[100000];
   long long int resultsNegativeBelow100k[100000];
   memset(resultsNegativeTo100k,-1,sizeof(resultsNegativeTo100k));
   memset(resultsPositiveTo100k,-1,sizeof(resultsPositiveTo100k));
   memset(resultsPositiveTo100k,-1,sizeof(resultsPositiveAbove100k));
   memset(resultsPositiveTo100k,-1,sizeof(resultsNegativeBelow100k));
  // long long int resultsBothAbove100k[10000000];
   long long int arr[pravi][2];
   for(int i=0;i<pravi;i++)
   {
      long long int left;
       long long int right;
       cin>>left;
       cin>>right;
       if(left>right)
       {
          long long int temp=left;
           left=right;
           right=temp;
       }

      arr[i][0]=left;
      arr[i][1]=right;
   }
   int tochici[tochki];
   for(int i=0;i<tochki;i++)
   {
       cin>>tochici[i];
   }
   for(int i=0;i<tochki;i++)
   {
       long long int res=0;
       if(tochici[i]>=0&&tochici[i]<100000)
       {
           if(resultsPositiveTo100k[tochici[i]]==-1)
           {
               for(int k=0;k<pravi;k++)
               {
                   if(arr[k][0]<=tochici[i]&&arr[k][1]>=tochici[i])
                   {
                       res++;
                   }
               }
               resultsPositiveTo100k[tochici[i]]=res;
               cout<<res<<" ";
           }
           else{
                        cout<<resultsPositiveTo100k[tochici[i]]<<" ";
           }
       }
       else if(tochici[i]<0&&tochici[i]>-100000)
       {
           long long int numtoWorkWith=abs(tochici[i]);
         if(resultsNegativeTo100k[numtoWorkWith]==-1)
           {
               for(int k=0;k<pravi;k++)
               {
                   if(arr[k][0]<=tochici[i]&&arr[k][1]>=tochici[i])
                   {
                       res++;
                   }
               }
               resultsNegativeTo100k[numtoWorkWith]=res;
               cout<<res<<" ";
           }
           else{
            cout<<resultsNegativeTo100k[numtoWorkWith]<<" ";
           }
       }
       else if(tochici[i]>=100000)
       {
           if(resultsNegativeTo100k[tochici[i]-100000]==-1)
           {
               for(int k=0;k<pravi;k++)
               {
                   if(arr[k][0]<=tochici[i]&&arr[k][1]>=tochici[i])
                   {
                       res++;
                   }
               }
               resultsNegativeTo100k[tochici[i]-100000]=res;
               cout<<res<<" ";
           }
           else{
            cout<<resultsNegativeTo100k[tochici[i]]<<" ";
           }
       }

   }

}
