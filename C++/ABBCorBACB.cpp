    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    int finRes=0;
    void Recursion(string word,int res)
    {
        if(wordMax[word]>=res&&res!=0)
        {
            return;
        }
        wordMax[word]=res;
        finRes=max(finRes,res);
        for(int i=0;i<word.size()-1;i++)
        {
            if(word[i]=='A'&&word[i+1]=='B')
            {
                string copyWord=word;
                copyWord[i]='B';copyWord[i+1]='C';
                Recursion(copyWord,res+1);
            }
            else if(word[i]=='B'&&word[i+1]=='A')
            {
                string copyWord=word;
                copyWord[i]='C';
                copyWord[i+1]='B';
                Recursion(copyWord,res+1);
            }
        }
    }

    int main()
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            finRes=0;
            string word;
            cin>>word;
            Recursion(word,0);
            cout<<finRes<<"\n";
        }
    }
