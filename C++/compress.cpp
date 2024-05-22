#include<iostream>
using namespace std;
void printVariations(int currentSum);
int suma=0;
int upToNumber=0;
long long int countCombos=0;
int main(int argc, char argv[])
{
    cin>>suma;
    cin>>upToNumber;
    printVariations(0);
    cout<<countCombos;
}
void printVariations(int currentSum)
{
    if(currentSum>=suma)
    {
        if(currentSum==suma)
        {
          countCombos++;
        }
        return;
    }
    for(int i=1;i<=upToNumber;i++)
    {
        printVariations(currentSum+i);
        cout<<currentSum+i<<"\n";
    }
}
