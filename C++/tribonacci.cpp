#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
   int first=0;
   int second=0;
   int third=1;
   int steps=3;
   int p;
   cin>>p;
   int met[p];
   memset(met,false,p);
   met[1%p]=true;
   while(true)
   {
       int temp=third;
       third=third+first+second;
       first=second;
       second=third;
       steps++;
       if(met[third%p]==true)
       {
        cout<<steps;
        return 0;
       }
       else{
        met[third%p]=true;
       }
   }

}
