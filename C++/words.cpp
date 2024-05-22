    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        unordered_map<char,int> val;
        char start='a';
        int counter=1;
       while(start<='z')
       {
           val[start]=counter;
           start++;counter++;
       }
       start='A';
       counter=1;
       while(start<='Z')
       {
           val[start]=counter;
           start++;counter++;
       }
       int n;
       cin>>n;
       string word;
       int mostPoints=0;
       string bestWord="";
       for(int i=0;i<n;i++)
       {
           cin>>word;
           int currentSum=0;
           double prev=0.5;
           for(int s=0;s<word.size();s++)
           {
               prev*=2;
               currentSum+=val[word[s]]*(prev);
           }
           if(currentSum>mostPoints)
           {
               mostPoints=currentSum;
               bestWord=word;
           }
       }
       cout<<bestWord;
    }
