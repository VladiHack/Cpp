#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int tests;
cin>>tests;
unordered_map<long long int,long long int> sumDigitsQuadrat;
for(int i=0;i<tests;i++)
{
    long long int current;long long int desired;long long int length;
    cin>>current>>desired>>length;
    int countMet=0;
    long long int prev=current;
            int takeNew=prev;int copyPrev=prev;
    if(current==desired)
    {
     countMet++;
    }
    for(int k=1;k<length;k++)
    {
        takeNew=prev;copyPrev=prev;
        prev=0;
        if(sumDigitsQuadrat[takeNew]!=0)
        {
            prev=sumDigitsQuadrat[takeNew];
        }
        else
        {
              while(takeNew!=0)
            {
            prev+=(takeNew%10)*(takeNew%10);
            takeNew/=10;
            }
            sumDigitsQuadrat[copyPrev]=prev;
        }
        if(prev==desired)
        {
            countMet++;
        }
    }
    cout<<countMet<<"\n";
}

}
