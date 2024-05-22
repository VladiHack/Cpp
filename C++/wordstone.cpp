#include <bits/stdc++.h>
using namespace std;
unordered_map<string,unordered_map<int,string>> first;
unordered_map<string,int> last;
int main()
{
    freopen("wordstone.in","r",stdin);
    freopen("wordstone.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<string> gods;
    for(int i=0;i<n;i++)
    {
        string name;
        cin>>name;
        gods.push_back(name);
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        string name;
        cin>>name;
        int counter=0;
        for(int s=0;s<n;s++)
        {
            if(name.size()<=gods[s].size())
            {
                string r = gods[s].substr(0,name.size());
                if(r==name)
                {
                    counter++;
                    continue;
                }
                string e= gods[s].substr(gods[s].size()-name.size(),name.size());
                if(e==name)
                {
                    counter++;
                }
            }
        }
        cout<<counter<<"\n";
    }


}
