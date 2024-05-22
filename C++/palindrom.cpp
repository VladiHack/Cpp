#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string Sum(string num1,string num2);
string arr[103]{""};
int main()
{
   int num;
   cin>>num;
   string first="32323";
   string second="227";
   arr[0]=first;
   arr[1]=second;
   /*
   for(int i=3;i<=num;i++)
   {
       arr[i]=Sum(arr[i-1],arr[i-2])
   }
   */
   cout<<Sum(first,second);

}
string Sum(string num1,string num2)
{
    string result="";
    int desetki=0;
       while(num2.size()>0)
       {
       int number1=(int)(num1[num1.size()-1]-'0');
       int number2=(int)(num2[num2.size()-1]-'0');
       int suma=(number1+number2+desetki)%10;
       desetki=(number1+number2+desetki)/10;
       result+=to_string(suma);
       num1.pop_back();
       num2.pop_back();
       }
       if(desetki!=0)
       {
           result+=to_string(desetki);
       }
       for(int i=0;i<result.size()/2;i++)
       {
           char current=result[i];
           result[i]=result[result.size()-1-i];
           result[result.size()-1-i]=current;
       }
       return result;
}

