#include<iostream>
using namespace std;
int main(int argc, char argv[])
{
int stringsToRead;
cin>>stringsToRead;
string arr[stringsToRead];
for(int i=0;i<stringsToRead;i++)
{
    cin>>arr[i];
}
for(int i=0;i<stringsToRead;i++)
{
    int oddMultiply=0;
    int oddPlus=0;
    bool specialEvenSequence=false;
    int keepLastDigit=-1;
    int secondLastDigit=-1;
    bool pluses=false;
    bool mulitplies=false;
    for(int k=0;k<arr[i].size();i++)
    {
        if(arr[i][k]!='+'&&arr[i][k]!='*')
        {
            if(pluses==false&&mulitplies==false)
            {
                   keepLastDigit=arr[i][k]-'0';
            }
            else
            {
                secondLastDigit=arr[i][k]-'0';
            }

        }
        else
        {
            if(arr[i][k]=='+')
            {
                pluses=true;
                specialEvenSequence=false;
            }
            else{
                mulitplies=true;
            }

            if(keepLastDigit!=-1&&secondLastDigit!=-1)
            {
                if(pluses==true)
                {
                    odd+=keepLastDigit%2;
                }
                else if(keepLastDigit%2==0||secondLastDigit%2==0)
                {
                    specialEvenSequence=true;
                }
            }
        }
    }
}
}
