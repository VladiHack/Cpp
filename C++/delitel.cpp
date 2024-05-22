    #include<iostream>
    #include <bits/stdc++.h>
    using namespace std;
    int main(int argc, char argv[])
    {
    ios_base::sync_with_stdio(false);
     int n;
     cin>>n;
     vector<bool> prime(100000000);
     vector<long long int> copyPrime;
        for (long long int p = 2; p * p <=n*50; p++)
        {
            if (prime[p] == false)
            {
                copyPrime.push_back(p);
                for (int i = p * p; i <= n*50; i += p)
                    prime[i] = true;
            }
        }


        long long int last=2;
        for(int i=2;i<=n;i++)
        {
            long long int toAdd=0;
            for(long long int k=last;k>=0;k--)
            {
            vector<int>::iterator itr = std::find(v.begin(), v.end(), key);
            if (itr != v.cend())
            {
                std::cout << "Element present at index " << std::distance(v.begin(), itr);
            }
            }
            last=last+toAdd;
            cout<<last<<"\n";
        }

        cout<<last;

    }
