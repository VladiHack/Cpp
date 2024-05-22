#include<iostream>
using namespace std;
int main(int argc, char argv[])
{
 string word;
 cin>>word;

 while(true)
 {
 bool changes=false;
 int indexFirst=-1;
 int indexLast=-1;
 for(int i=0;i<word.size();i++)
 {
     if(word[i]!='0')
     {
         if(indexFirst==-1)
         {
           indexFirst=i;
         }
         else if(indexLast==-1&&indexFirst!=-1)
         {
             indexLast=i;
         }

             if(indexFirst!=-1&&indexLast!=-1)
             {
                 if(word[indexFirst]==word[indexLast])
                 {
                         changes=true;
                 word[indexFirst]='0';
                 word[indexLast]='0';
                 indexFirst=-1;
                 indexLast=-1;
                 }
                 else{
                    indexFirst=indexLast;
                    indexLast=-1;
                 }

             }


     }

 }
 if(changes==false)
 {
     break;
 }
 }
 for(int i=0;i<word.size();i++)
 {
     if(word[i]!='0')
     {
         cout<<word[i];
     }
 }

}
