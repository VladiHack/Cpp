#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
long long int start;long long int endIndex;
cin>>start>>endIndex;
int counter=0;
for(long long int i=start;i<=endIndex;i++)
{
    //x^2+x-i
    long long int d=1;
    d+=i;
    d+=i;
    d+=i;
    d+=i;
    long long int korenche=sqrt(d);
    d/=korenche;
    if(korenche==d&&korenche%2==1)
    {
        counter++;
    }
}
cout<<counter;
}
