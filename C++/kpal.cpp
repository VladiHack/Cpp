#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string S);
bool found=false;
string seq="";
void Recursion(int steps,string word,unordered_map<string,bool> met)
{
    if(found||met[word])
    {
        return;
    }
    met[word]=true;
    if(isPalindrome(word))
    {
        found=true;
        return;
    }
     if(steps==0)
    {
       return;
    }
    for(int i=0;i<word.size();i++)
    {
        string copyWord=word;
        copyWord.erase(i,1);
        Recursion(steps-1,copyWord,met);
    }
}
bool isPalindrome(string S)
{
    for (int i = 0; i < S.length() / 2; i++)
    {
        if (S[i] != S[S.length() - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int tests;
cin>>tests;
for(int i=0;i<tests;i++)
{
    int k;string word;
    unordered_map<string,bool> met;
    found=false;
    cin>>k>>word;
    if(k>=word.size()-1)
    {
        seq+="1";
    }
    else{
         Recursion(k,word,met);
    if(found)
    {
        seq+="1";
    }
    else{
        seq+="0";
    }
    }

}
cout<<seq;

}
