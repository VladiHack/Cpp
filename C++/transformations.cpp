#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int arr[1000]{0};
void AddOne();
int main()
{
    //0 minava v 1 i 0     1 minava v 0 i 1
    int n;
    cin>>n;
    if(n<=2)
    {
        cout<<0;
    }
    else
    {
     unsigned long long int first=1;
     int pos=999;
     for(int i=3;i<=n;i++)
     {
         /*
         first*=2;
         if(i%2==1)
         {
             first++;
         }
          arr[position]=first;
        */
        AddOne();
        for(int i=999;i>=999-n;i--)
        {
            cout<<arr[i];
        }
        cout<<"\n";
     }
    }

     return 0;
}
void AddOne()
{
    int position=999;
    while(true)
    {
     if(arr[position]==9)
     {
         arr[position-1]++;
         arr[position]=0;
         position--;
     }
     else if(arr[position]==10)
     {
         arr[position]=1;
         arr[position-1]++;
         position--;
     }
     else
    {
        arr[position]++;
        break;
     }

    }
    }
