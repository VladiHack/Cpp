#include<iostream>
#include <bits/stdc++.h>
using namespace std;
  int sizeWord;long long int posSearched;
  long long int permutations[27];
void Recursion(long long int pos,string s)
{
    if(posSearched==0)
    {
        return;
    }
    if(permutations[sizeWord-pos]<posSearched&&sizeWord-pos<=20)
    {
        posSearched-=permutations[sizeWord-pos];
        return;
    }

    if(pos==sizeWord)
    {
        posSearched--;
        if(posSearched==0)
        {
        cout<<s<<"\n";
        }
        return;
    }
    for(int i=0;i<sizeWord;i++)
    {
        char conv=char(97+i);
        if(s.find(conv)==std::string::npos)
        {
            Recursion(pos+1,s+conv);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    memset(permutations,1,sizeof(permutations));
    permutations[1]=1;
    for(int i=2;i<=20;i++)
    {
        permutations[i]=permutations[i-1]*i;
    }
    for(int i=0;i<n;i++)
    {
      cin>>sizeWord>>posSearched;
      Recursion(0,"");
    }
}
