#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string result="";
bool met=false;
void Recursion(queue<int> a,stack<int> b,stack<int> c,stack<int> desired)
{
    if(met)
    {
        return;
    }
    if(a.size()==0&&c.size()==0)
    {
        stack<int> copyDesired=desired;
        stack<int> copyC=c;
        while(copyC.size()!=0)
        {
            if(copyC.top()!=copyDesired.top())
            {
               return;
            }
            copyC.pop();
            copyDesired.pop();
        }
        met=true;
        return;
    }
    if(a.size()!=0)
    {
        int transfer=a.front();
        queue<int> copyA=a;
        copyA.pop();
        stack<int> copyC=c;
        copyC.push(transfer);
        Recursion(copyA,b,copyC,desired);
    }
    if(c.size()!=0)
    {
        int transfer=c.top();
        stack<int> copyC=c;
        copyC.pop();
        stack<int> copyB=b;
        copyB.push(transfer);
        Recursion(a,copyB,copyC,desired);
    }
}
int main()
{
int n;
cin>>n;
for(int i=0;i<5;i++)
{
    queue<int> a;
    stack<int> b;
    stack<int> c;
    stack<int> desired;
    for(int k=0;k<n;k++)
    {
        int number;
        cin>>number;
        a.push(k+1);
        desired.push(number);
    }
    Recursion(a,b,c,desired);
    if(met)
    {
        met=false;
        result+="1";
    }
    else{
        result+="0";
    }

}
cout<<result;
}
