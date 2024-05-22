#include<iostream>
#include<cmath>
#include<stack>
#include<climits>
#include <bits/stdc++.h>

using namespace std;
string currentPerm;int n;
unordered_map<int,bool> resMet;
void GivePermutations(int index,bool lastNum,string arr,string byFar)
{
    if(index==arr.size()-1)
    {
        //int  - '0'
       stack<int> numbers;
       stack<int> operators;
       for(int i=0;i<byFar.size()-1;)
       {
           int numToAdd=0;
           if(byFar[i]=='*')
           {
                 while(byFar[i]=='*'&&i<byFar.size())
               {
                  int getMultiplied=(byFar[i-1]-'0');
                  getMultiplied*=(byFar[i+1]-'0');
                  numToAdd+=getMultiplied;
                  i+=2;
               }
           }
           else if(byFar[i]!='+'&&byFar[i]!='-')
           {
               int convert=byFar[i]-'0';
               if(byFar[i-1]!='*'&&byFar[i+1]!='*')
               {
                   numbers.push(convert);
                   if(byFar[])
               }
           }
        numbers.push(numToAdd);
       }
        return;
    }
   if(lastNum==false)
   {
       GivePermutations(index+1,true,arr,byFar+arr[index]);
   }
   else
   {
      GivePermutations(index+1,false,arr,byFar+"+");
     GivePermutations(index+1,false,arr,byFar+"*");
     GivePermutations(index+1,false,arr,byFar+"-");
   }

}
    int main()
    {
        int n;
        cin>>n;
       string arr="";
        for(int i=0;i<n;i++)
        {
            string read;
            cin>>read;
            arr+=read+" ";
        }
        string byFar="";
        GivePermutations(0,false,arr,byFar);
        cout<<countUnique<<"\n";
    }
