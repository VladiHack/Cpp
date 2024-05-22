#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int length;
    cin>>length;
    bool met[length];
    memset(met,false,sizeof(met));
    int first;
    cin>>first;
    int counter=0;
    for(int i=0;i<first;i++)
    {
        int index;
        cin>>index;
        index--;
        if(!met[index])
        {
            met[index]=true;
            counter++;
        }
    }
    int second;
    cin>>second;
    for(int i=0;i<second;i++)
    {
        int index;
        cin>>index;
        index--;
        if(!met[index])
        {
            met[index]=true;
            counter++;
        }
    }
    if(counter==length)
    {
        cout<<"I become the guy."
    }
    else{
        cout<<"Oh, my keyboard!";
    }

}
