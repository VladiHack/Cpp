 #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
        double power(double num,int n);
    int main()
    {
        double num;int n;
        cin>>num>>n;
        double powered=power(num,n);
        cout<<powered;
    }
    double power(double num,int n)
    {
        if(n==0)
        {
            return 1;
        }
        return power(num,n-1)*num;
    }
