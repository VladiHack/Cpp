#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int number;
    cin>>number;
    for(int i=0;i<number;i++)
    {
        string equation;
        cin>>equation;
        int pluses=0;
        int multNums=1;
        char left = ' ';
        char right = ' ';
        int lastDigit=0;
        for(int k=0;k<equation.size();k++)
        {
            if(equation[k]!='+'&&equation[k]!='*')
            {
                string convert=equation[k];
                lastDigit=(int) convert;
            }
            else
            {
                if(left==' ')
                {
                    left=equation[k];
                    right=left;
                }
                else if(left!=' '&&right!=' ')
                {
                    left=right;
                    right=equation[k];
                }


            }
        }
    }

}
