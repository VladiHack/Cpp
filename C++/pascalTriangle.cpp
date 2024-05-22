#include<iostream>
using namespace std;
int main(int argc, char argv[])
{
    int numberKids;
    cin>>numberKids;
    char line[numberKids];
    int totalNumber=0;
    int maxK=0;
    for(int i=0;i<numberKids;i++)
    {
        cin>>line[i];
    }
    while(true)
    {
        int k=maxK+1;
        bool countOnes=true;
        int consequitiveOnes=0;
        int consequitiveZeros=0;
        int ones=0;
        int zeros=0;

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
        long long int newNumber=(consequitiveOnes+consequitiveZeros)*k;
         consequitiveOnes=0;
         consequitiveZeros=0;
         ones=0;
         zeros=0;
         countOnes=false;

        //start with zeros
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
        long long int newNumber2=(consequitiveOnes+consequitiveZeros)*k;
        newNumber=max(newNumber2,newNumber);
            if(totalNumber<newNumber)
            {
                totalNumber=newNumber;
                maxK++;
            }
            else
            {
                cout<<totalNumber<<" "<<maxK;
                return 0;
            }

    }

}
