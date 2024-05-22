#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int one=0;int zero=0;
string met="NO";
void Recursion(int onesRemain,int zerosRemain,int stepen,int number,string msg,bool lastOne)
{
    if(met!="NO")
    {
        return;
    }
    if(onesRemain==0)
    {
        if(number==0)
        {
            met=msg;
            while(zerosRemain>0)
            {
                zerosRemain--;
                met+="0";
            }
        }
        return;
    }
    if(zerosRemain==0&&onesRemain>1)
    {
        return;
    }
    if(lastOne==false)
    {
            if(stepen%2==0)
            {
                Recursion(onesRemain-1,zerosRemain,stepen+1,(number+4)%3,msg+"1",true);
            }
            else{
            Recursion(onesRemain-1,zerosRemain,stepen+1,(number+2)%3,msg+"1",true);
            }
    }
    if(zerosRemain>0)
    {
        Recursion(onesRemain,zerosRemain-1,stepen+1,number,msg+"0",false);
    }


}
int main()
{

string s;
cin>>s;
for(int i=0;i<s.size();i++)
{
   if(s[i]=='1')
   {
       one++;
   }
   else if(s[i]=='0')
    {
    zero++;
   }
}
if(one==zero)
{
    met="10";
    //pochva ot purva vurti prez nechetni
    int num=1;
    for(int i=0;i<one-1;i++)
    {
        num+=2;
        met.insert(0,"10");
    }
    if(num%3==0)
    {
        cout<<met;
    }
    else{
        cout<<"NO";
    }
    return 0;
}
if(one<zero)
{
    Recursion(one-1,zero,1,1,"1",true);

    Recursion(one,zero-1,1,0,"0",false);
}
cout<<met;
}
