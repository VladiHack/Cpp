#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
    int numberOfWorks;
    int maxPages;
    cin>>numberOfWorks;
    cin>>maxPages;
    double pages[maxPages+1]{0};
    for(int i=0;i<numberOfWorks;i++)
    {
        int numberPages;
        double pricePerPage;
        cin>>numberPages;
        cin>>pricePerPage;
        if(pages[numberPages]==0)
        {
            pages[numberPages]=pricePerPage;
        }
        else
        {
            pages[numberPages]=max(pages[numberPages],pricePerPage);
        }
    }
}

