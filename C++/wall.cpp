#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unordered_map<string,bool> wordContainer;
vector<string> names;
string res="";
void CheckString(string read,int index,string current,string collected)
{
    for(int i=index;i<read.size();i++)
    {
        current+=read[i];
        if(wordContainer[current])
        {
            CheckString(read,i+1,"",collected+" "+current);
        }
    }
    cout<<collected<<"\n";
}
void permute(string space,string slqto,int counter)
{
    if(counter==names.size())
    {
       CheckString(slqto,0,"","");
    }
   for(int i=0;i<names.size();i++)
   {
       string s=" ";
       s+=names[i];
       s+=" ";
       if(space.find(s)!=std::string::npos)
       {
        continue;
       }
       else{
        permute(space+s,slqto+names[i],counter+1);
       }
   }
}

int main()
{
int n;int m;
cin>>n>>m;
for(int i=0;i<n;i++)
{
    string s;
    cin>>s;
    names.push_back(s);
}
permute("","",0);
int words;cin>>words;
for(int i=0;i<words;i++)
{
    string num;
    cin>>num;
    wordContainer[num]=true;
}
}
