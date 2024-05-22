#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int reverseDigits(int num)
{
    int rev_num = 0;
    while (num > 0) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}
int main()
{
    const int N = 100000001;
vector<int> lp(N+1);
vector<int> pr;

for (int i=2; i <= N; ++i)
{
    if (lp[i] == 0)
     {
        lp[i] = i;
        pr.push_back(i);
    }
    for (int j = 0; i * pr[j] <= N; ++j)
    {
        lp[i * pr[j]] = pr[j];
        if (pr[j] == lp[i])
         {
            break;
        }
    }
}

    while(true)
    {
        string res;
        cin>>res;
        if(res=="quit")
        {
            break;
        }
        int a;
        cin>>a;
        if(res=="A"||res=="a")
        {
            int b;
            cin>>b;
            vector<int>::iterator lower;
           lower=lower_bound(pr.begin(), pr.end(), a);
                    vector<int>::iterator upper;
            upper=upper_bound(pr.begin(), pr.end(), b);
           cout<<(upper-pr.begin())-(lower-pr.begin())<<"\n";
        }
        else if(res=="B"||res=="b")
        {
            cout<<lp[a]<<"\n";
        }
        else if(res=="C"||res=="c")
        {
            if(lp[a]==a)
            {
                cout<<1<<"\n";
            }
            else{
                cout<<0<<"\n";
            }
        }
        else if(res=="D"||res=="d")
        {
            int reversed=reverseDigits(a);
            if(lp[reversed]==reversed)
            {
                cout<<1<<"\n";
            }
            else{
                cout<<0<<"\n";
            }
        }
        else if(res=="E"||res=="e")
        {
            if(lp[a]==a)
            {
                cout<<a<<"\n";
                continue;
            }
            vector<int>::iterator lower;
            lower=lower_bound(pr.begin(), pr.end(),a);
            int indexBigger=lower-pr.begin();
            int indexSmaller=indexBigger-1;
            if(indexBigger<pr.size())
            {
                 if(a-pr[indexSmaller]<pr[indexBigger]-a)
                {
                    cout<<pr[indexSmaller]<<"\n";
                }
                else if(a-pr[indexSmaller]==pr[indexBigger]-a)
                {
                    cout<<pr[indexSmaller]<<" "<<pr[indexBigger]<<"\n";
                }
                else
                {
                    cout<<pr[indexBigger]<<"\n";
                }
            }
            else
            {
                cout<<pr[indexSmaller]<<"\n";
            }

        }
        else if(res=="F"||res=="f")
        {
           vector<int>::iterator upper;
           upper=lower_bound(pr.begin(), pr.end(), a);
           cout<<(upper-pr.begin())<<"\n";
        }
    }
}
