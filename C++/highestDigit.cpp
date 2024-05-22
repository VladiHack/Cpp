#include<iostream>
using namespace std;
void Recursion(string s,int index);
char maximum='0';
int main(int argc, char argv[])
{
string s;
cin>>s;
Recursion(s,0);
cout<<maximum;
}
void Recursion(string s,int index)
{
    if(index==s.size())
    {
        return;
    }
    if(s[index]>maximum)
    {
        maximum=s[index];
    }
    Recursion(s,index++);
}
