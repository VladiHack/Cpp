#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
string name="";
vector<string> names;
while(cin>>name)
{
    names.push_back(name);
}
unordered_map<string,vector<string>> nameCollector;
string specialName=names[names.size()-1];
for(int i=0;i<names.size()-1;i+=2)
{
   for(int k=0;k<nameCollector[names[i]].size();k++)
   {
       if (std::count(nameCollector[names[i+1]].begin(), nameCollector[names[i+1]].end(),nameCollector[names[i]][k]))
    {
    }
    else
    {
        nameCollector[names[i+1]].push_back(nameCollector[names[i]][k]);
    }
   }
     for(int k=0;k<nameCollector[names[i+1]].size();k++)
   {
       if (std::count(nameCollector[names[i]].begin(), nameCollector[names[i]].end(),nameCollector[names[i+1]][k]))
    {
    }
    else
    {
        nameCollector[names[i]].push_back(nameCollector[names[i+1]][k]);
    }
   }

   nameCollector[names[i]].push_back(names[i+1]);
   nameCollector[names[i+1]].push_back(names[i]);
}
cout<<nameCollector[specialName].size();

}
