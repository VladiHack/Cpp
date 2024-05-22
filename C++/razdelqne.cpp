#include<iostream>
using namespace std;
int main(int argc, char argv[])
{
   string sequence;
   cin>>sequence;
   int countSequences=0;
   char beggining=sequence[0];
   for(int i=1;i<sequence.size();i++)
   {
       if(sequence[i]!=beggining&&sequence[i]!='t'&&beggining!='t')
       {
           sequence[i]='t';
           sequence[i-1]='t';
           countSequences++;
       }
       beggining=sequence[i];
   }
   cout<<countSequences;
}
