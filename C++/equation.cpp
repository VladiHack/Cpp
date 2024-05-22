#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int minSteps=1000;
void Recursion(int a,int b,int c,int steps);
int main()
{
int a;int b;int c;
cin>>a>>b>>c;
Recursion(a,b,c,0);
if(minSteps==1000)
{
    cout<<-1;
    return 1;
}
cout<<minSteps;
}
void Recursion(int a,int b,int c,int steps)
{
    cout<<a<<" "<<b<<" "<<c<<"\n";
    if(a==b&&b==c||steps>=minSteps)
    {
        return;
    }
    if((a==0&&b==0)||(a==0&&c==0)||(b==0&&c==0))
    {
         minSteps=min(steps,minSteps);
        return;
    }
    if(b-a>=0)
    {
        Recursion(2*a,b-a,c,steps+1);
    }
    if(c-a>=0)
    {
        Recursion(2*a,b,c-a,steps+1);
    }
    if(c-b>=0)
    {
        Recursion(a,2*b,c-b,steps+1);
    }
    if(b-c>=0)
    {
        Recursion(a,b,2*c,steps+1);
    }
    if(a-b>=0)
    {
        Recursion(a-b,b*2,c,steps+1);
    }
    if(a-c>=0)
    {
        Recursion(a-c,b,c*2,steps+1);
    }
}



