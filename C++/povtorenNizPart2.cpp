#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string read;string res="";
unordered_map<int,string> substrings;
void Recursion(int index,string currentString)
{
    if(currentString.size()>res.size()/2)
    {
        return;
    }
    if(currentString.size()>=res.size())
    {
        if(substrings[index]=="")
        {
            substrings[index]=read.substr(index,read.size()-index-1);
            cout<<substrings[index]<<"\n";
        }
         if(substrings[index].find(currentString)!=string::npos)
        {
        if(res.size()<currentString.size())
        {
            res=currentString;
        }
        else if(res.size()==currentString.size()&&res>currentString)
        {
            res=currentString;
        }
        }
    }

    for(int i=index;i<read.size();i++)
    {
        Recursion(i+1,currentString+read[i]);
    }
}
int main()
{
int t;
cin>>t;
for(int i=0;i<t;i++)
{
    substrings.clear();
    res="";
    cin>>read;
    Recursion(0,"");
    cout<<res<<"\n";
}
}
