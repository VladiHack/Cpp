#include<iostream>
using namespace std;
int main(int argc, char argv[])
{
    int numberKids;
    cin>>numberKids;
    char line[numberKids];
    int totalNumber=0;
    int maxK=0;
    int k=1;
    int countOne=0;
    for(int i=0;i<numberKids;i++)
    {
        cin>>line[i];
        if(line[i]=='1')
        {
        countOne++;
        }
    }
    int smallerDigit=min(countOne,numberKids-countOne);
    while(true)
    {
        bool countOnes=true;
        int consequitiveOnes=0;
        int consequitiveZeros=0;
        int ones=0;
        int zeros=0;
        int firstOnePos=-1;

        //start with ones
        for(int i=0;i<numberKids;i++)
        {
            if(countOnes&&line[i]=='1')
            {
                ones++;
                if(ones==k)
                {
                    consequitiveOnes++;
                    ones=0;
                    countOnes=false;
                    if(firstOnePos==-1)
                    {
                        firstOnePos=i;
                    }
                }
            }
            else if(countOnes==false&&line[i]=='0')
            {
                zeros++;
                if(zeros==k)
                {
                    consequitiveZeros++;
                    zeros=0;
                    countOnes=true;
                }
            }
        }
        long long int newNumber=0;
        if(consequitiveOnes!=0&&consequitiveZeros!=0)
        {

            newNumber=(consequitiveOnes+consequitiveZeros)*k;
        }
         consequitiveOnes=0;
         consequitiveZeros=0;
         ones=0;
         zeros=0;
         countOnes=false;

        //start with zeros
        for(int i=0;i<firstOnePos;i++)
        {
            if(countOnes==true&&line[i]=='1')
            {
                ones++;
                if(ones==k)
                {
                    consequitiveOnes++;
                    ones=0;
                    countOnes=false;
                }
            }
            else if(countOnes==false&&line[i]=='0')
            {
                zeros++;
                if(zeros==k)
                {
                    consequitiveZeros++;
                    zeros=0;
                    countOnes=true;
                }
            }
        }
        long long int newNumber2=0;
        if(consequitiveOnes!=0&&consequitiveZeros!=0)
        {
            if(consequitiveOnes!=consequitiveZeros)
            {
                newNumber2=newNumber+consequitiveOnes*k+consequitiveZeros*k;
            }
            else{
                newNumber2=newNumber+consequitiveOnes*k+consequitiveZeros*k;
            }
        }
        else if(consequitiveZeros==1)
        {
            newNumber2=newNumber+1;
        }

        newNumber=max(newNumber2,newNumber);
            if(totalNumber<newNumber)
            {
                totalNumber=newNumber;
                maxK=k;
            }
            else if(newNumber==0||k==smallerDigit)
            {
                cout<<totalNumber<<" "<<maxK;
                return 0;
            }
             k++;
    }

}
