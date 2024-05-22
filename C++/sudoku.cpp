#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string read;
    string readNew;
    int countLines=0;
    while(getline(cin,readNew))
    {
        if(readNew=="")
        {
            break;
        }
        read+=readNew+"\n";
        countLines++;
    }
    bool met[11];
    cout<<countLines;
    for(int i=0;i<countLines;i++)
    {
        int k=0;
        while(true)
        {
            if(read[i][k]<'0'||read[i][k]>'9')
            {
                break;
            }
            if(read[i][k]=="0")
            {
                    memset(met,false,sizeof(met));
                    met[read[i-1][k]-'0']=true;
                    met[read[i][k-1]-'0']=true;
                    met[read[i][k+1]-'0']=true;
                    met[read[i+1][k]-'0']=true;
                    met[read[i+1][k-1]-'0']=true;
                    met[read[i-1][k+1]-'0']=true;
                    met[read[i-1][k-1]-'0']=true;
                    met[read[i+1][k+1]-'0']=true;
                    for(int i=1;i<=9;i++)
                    {
                       if(met[i]==false)
                       {
                           read[i][k]=to_string(i);
                       }
                    }
            }
            k+=2;
        }
    }



}
