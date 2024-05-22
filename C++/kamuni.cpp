#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int minSteps=100;
void Recursion(int a,int b,int c,int steps);
int main()
{
int a;int b;int c;
cin>>a>>b>>c;
int smallest=a;
int biggest=c;
if(smallest<b)
{
    smallest=b;
}
if(smallest<c)
{
    smallest=c;
}
if(biggest>a)
{
    biggest=a;
}
if(biggest>b)
{
    biggest=b;
}
Recursion(smallest,a+b+c-smallest-biggest,biggest,0);
if(minSteps==100)
{
    cout<<-1;
    return 1;
}
cout<<minSteps;
}
void Recursion(int a,int b,int c,int steps)
{
    if(steps>=minSteps||)
    {
        return;
    }
}



