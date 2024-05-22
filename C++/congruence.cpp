#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
   string word;
   cin>>word;
   char biggest[word.size()];
   int taken[word.size()]{0};
   int countFound=0;
   char lastBiggest='A';
   char biggestChar='Z';
   string smaller="";
   string bigger="";
   while(countFound<word.size())
   {
      int biggestIndex=-1;bool differentBig=true;
      for(int i=0;i<word.size();i++)
        {
                if(taken[i]==0)
                {
                    if(biggestIndex==-1)
                    {
                        biggestIndex=i;
                    }
                    if(countFound>0)
                   {
                    if(word[i]==lastBiggest&&countFound)
                    {
                    countFound++;
                    biggestChar++;
                    biggest[i]=biggestChar;
                    biggestIndex=i;
                    differentBig=false;
                    taken[i]=1;
                    break;
                    }
                    else if(word[biggestIndex]<word[i])
                    {
                        biggestIndex=i;
                    }

                }
                else if(word[biggestIndex]<word[i])
                {
                   biggestIndex=i;

                }
            }

        }
        if(differentBig==true)
        {
            //da opravq posledniq symvol
        biggest[biggestIndex]=biggestChar;
         lastBiggest=word[biggestIndex];
        taken[biggestIndex]=1;
        countFound++;
        }
         biggestChar--;

   }
   char smallest='Z';
   for(int i=0;i<word.size();i++)
   {
      bigger+=biggest[i];
      smallest=min(smallest,biggest[i]);
   }
   int difference=(int)(smallest-'A');
   for(int i=0;i<word.size();i++)
   {
       smaller+=(char)(biggest[i]-difference);
   }
   cout<<smaller<<"\n"<<bigger;



}

