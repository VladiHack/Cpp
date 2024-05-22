#include<iostream>
using namespace std;
int n;int tables;int happiness=-1;
int arr[501];
void Recursion(int currentTable,int happy,int lastTableHorses,int whiteHorses,int currentHorse)
{
    if(happy>=happiness&&happiness!=-1)
    {
        return;
    }
    if(currentHorse==n)
    {
        happy+=(lastTableHorses-whiteHorses)*(whiteHorses);
        if(happiness==-1)
        {
            happiness=happy;
        }
        happiness=min(happiness,happy);
        return;
    }
    if(currentTable<tables&&lastTableHorses!=0)
    {
        Recursion(currentTable+1,happy+(lastTableHorses-whiteHorses)*whiteHorses,0,0,currentHorse);
    }
    if(arr[currentHorse]==1)
    {
        Recursion(currentTable,happy,lastTableHorses+1,whiteHorses+1,currentHorse+1);
    }
    else
    {
        Recursion(currentTable,happy,lastTableHorses+1,whiteHorses,currentHorse+1);
    }
}
int main(int argc, char argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>tables;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
            arr[i]=num;
    }
    Recursion(1,0,0,0,0);
    cout<<happiness;

}
