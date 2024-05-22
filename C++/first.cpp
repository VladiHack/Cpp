#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool CheckIfNumberLeadsToMetTwice(long long int sum);
long long int repeatedNonMatch[10000];int countRecordings=0;
int main()
{
  unsigned long long int a;
  unsigned long long int b;
  int quadrats[10];
  cin>>a>>b;
  int countMet=0;
  for(int i=0;i<10;i++)
  {
      quadrats[i]=i*i;
  }
  for(unsigned long long int i=a;i<=b;i++)
  {
      unsigned long long int copyI=i;
      //2   4    16    37    58     65    61   37
      //5   25   29    85    65     61    37   58    65
      vector <long long int> nums;
      bool metTwice=false;bool sumOne=false;
      long long int sum=0;
      while(metTwice==false&&sumOne==false)
      {
          int last=copyI%10;
         sum+=quadrats[last];
         copyI/=10;
         if(copyI==0)
         {
             bool check=CheckIfNumberLeadsToMetTwice(sum);
             if(check)
             {
                 metTwice=true;
                 break;
             }
             if(sum==1)
             {
                 sumOne=true;
                 break;
             }
             else
            {
                if (find(nums.begin(), nums.end(),sum) != nums.end())
                {
                   metTwice=true;

                   for(int i=0;i<nums.size();i++)
                   {
                       repeatedNonMatch[countRecordings];
                       countRecordings++;
                   }
                   break;
                }
                else
                {
                 nums.push_back(sum);
                }
             }
             copyI=sum;
             sum=0;


         }
      }
      if(sumOne==true)
      {
          countMet++;
      }

  }
  cout<<countMet;
}
bool CheckIfNumberLeadsToMetTwice(long long int sum)
{
    for(int i=0;i<countRecordings;i++)
    {
        if(sum==repeatedNonMatch[i])
        {
            return true;
        }
    }
    return false;
}
