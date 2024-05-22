#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    // Find Minimum of a and b
    int result = min(a, b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }

    // Return gcd of a and b
    return result;
}
int main()
{
int lines;
cin>>lines;
unordered_map<double,unordered_map<double,bool>> metVector;
int countUnique=0;
bool vertical=false;
bool horizontal=false;
for(int i=0;i<lines;i++)
{
    int x1;int y1;int x2;int y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1>x2)
    {
        int tempX=x1;int tempY=y1;
        x1=x2;  y1=y2;
        x2=tempX; y2=tempY;
    }
    if(x1==x2||y1==y2)
    {
             if(x1==x2)
        {
            if(horizontal==false)
            {
                horizontal=true;
                countUnique++;
            }
        }
        if(y1==y2)
        {
            if(vertical==false)
            {
                vertical=true;
                countUnique++;
            }
        }
        continue;
    }
   int xVec=x2-x1;
   int yVec=y2-y1;
   int divisor=gcd(xVec,yVec);
   xVec/=divisor;
   yVec/=divisor;
   if(metVector[xVec][yVec]==false)
   {
       metVector[xVec][yVec]=true;
       metVector[yVec][xVec]=true;
       countUnique++;
   }

}
cout<<countUnique;
}
