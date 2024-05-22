
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int result;
    cin>>result;
    int steps=0;
    int removeOnes[1000000];  int countOnes=0;
    int substractTwo[1000000]; int countTwos=0;
    int substractThree[1000000];  int countThrees=0;
    while(true)
    {
        if(result==1)
        {
            break;
        }
        removeOnes[countOnes]=result-1;
        countOnes++;
        if(result%2==0)
        {
            substractTwo[countTwos]=result/2;
            countTwos++;
        }
        if(result%3==0)
        {
            substractThree[countThrees]=result/3;
            countThrees++;
        }
    }
    cout<<steps;

}

