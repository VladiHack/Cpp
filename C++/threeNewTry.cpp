    #include<iostream>
    #include <bits/stdc++.h>
    using namespace std;
    int n;int p;int a;int b;int r;
    unordered_map<int,bool> everMet;
    unordered_map<int,int> smallestSteps;
    void Recursion(int tempN,int steps)
    {
        if(everMet[tempN])
        {
            if(smallestSteps[tempN]<=steps)
            {
                return;
            }
        }
        if(steps!=0)
        {
        everMet[tempN]=true;
        smallestSteps[tempN]=steps;
        }
        if(tempN==r&&steps!=0)
        {
            return;
        }
        Recursion((tempN+a)%p,steps+1);
        Recursion((tempN+b)%p,steps+1);
    }
    int main(int argc, char argv[])
    {
          ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        cin>>n>>p>>a>>b>>r;
        Recursion(n,0);
        if(everMet[r])
        {
                    cout<<smallestSteps[r];
        }
        else{
            cout<<-1;
        }
    }
