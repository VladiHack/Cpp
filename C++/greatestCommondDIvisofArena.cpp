#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int gcdEuclidRemainderIter(int a, int b);
long long lcm(int a, int b);
int main(int argc, char *argv[])
{
    int n;
    int k;
    cin>>n;
    cin>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    long long NOD=arr[0];
    for(int i=1;i<n;i++)
    {
        NOD=lcm(NOD,arr[i]);
    }
    cout<<NOD;
    int primes[NOD+1];
    for(int i=1;i<=NOD;i++)
    {

    }
}
long long lcm(int a, int b)
 {
    return (long long)a * (b / gcdEuclidRemainderIter(a, b));
}
int gcdEuclidRemainderIter(int a, int b)
{
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}
