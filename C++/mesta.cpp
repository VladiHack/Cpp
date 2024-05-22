#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int a;int b;int c;
bool found=false;
string res="-1";
int sizer=0;
void Recursion(int B,int C,string msg,int pos,bool arr[])
{
    if(found)
    {
        return;
    }
    if(pos==sizer)
    {
        res=msg;
        found=true;
        return;
    }
    if(arr[pos])
    {
        Recursion(B,C,msg+"A",pos+1,arr);
    }
    else
    {
        if(msg[msg.size()-1]=='B'&&C>0)
        {
            Recursion(B,C-1,msg+"C",pos+1,arr);
        }
        else if(msg[msg.size()-1]=='C'&&B>0)
        {
            Recursion(B-1,C,msg+"B",pos+1,arr);
        }
        else if(msg[msg.size()-1]=='A')
        {
            if(B>0)
            {
                Recursion(B-1,C,msg+"B",pos+1,arr);
            }
            if(C>0)
            {
                Recursion(B,C-1,msg+"C",pos+1,arr);
            }
        }
    }


}
int main(int argc, char argv[])
{
cin>>a>>b>>c;
bool arr[a+b+c];
memset(arr,false,sizeof(arr));
sizer=a+b+c;
for(int i=0;i<a;i++)
{
    int pos;
    cin>>pos;
    arr[pos-1]=true;
}
if(arr[0])
{
    Recursion(b,c,"A",1,arr);
}
else{
    Recursion(b-1,c,"B",1,arr);
Recursion(b,c-1,"C",1,arr);
}

cout<<res;
}
