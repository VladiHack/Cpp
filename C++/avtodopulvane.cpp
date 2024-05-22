#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    while(true)
    {
        string read;
        cin>>read;
        if(read=="exit")
        {
            break;
        }
        int rows=stoi(read);
        int queries;
        cin>>queries;
        string arr[rows];
        vector<string> vec;
        for(int i=0;i<rows;i++)
        {
            cin>>arr[i];
            vec.push_back(arr[i]);
        }
        sort(vec.begin(),vec.end());
        for(int s=0;s<queries;s++)
        {
            int pos;string sub;
            string check="";
            cin>>pos>>sub;
            for(int i=0;i<vec.size();i++)
            {
                string subS=vec[i].substr(0,sub.size());
                if(subS==sub)
                {
                    check=vec[i+pos-1];
                    break;
                }
            }
            string beginning=check.substr(0,sub.size());
            if(beginning==sub)
            {
                for(int i=0;i<rows;i++)
                {
                    if(arr[i]==check)
                    {
                        cout<<i+1<<"\n";
                    }
                }
            }
            else{
                cout<<-1<<"\n";
            }
        }

    }


}
