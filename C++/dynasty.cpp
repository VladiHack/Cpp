 #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    unordered_map<string,string> sonFather;
      unordered_map<string,bool> isFather;
        unordered_map<string,vector<string>> arr;
              unordered_map<string,int> legacies;
      vector<string> fathers;
          void FindAncestors(string father);
    int main()
    {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
      int n;
      cin>>n;
      string wrong="";

      for(int i=0;i<n;i++)
      {
          string father;string son;
          cin>>father>>son;
          if(isFather[father]==false)
          {
              fathers.push_back(father);
              arr[father].push_back(son);
              legacies[father]=0;
              isFather[father]=true;
              sonFather[son]=father;
          }
          if(sonFather[son]=="")
          {
              sonFather[son]=father;
              arr[father].push_back(son);
          }
          else if(sonFather[son]!=father&&wrong=="")
          {
              wrong=son;
          }
      }
      if(wrong!="")
      {
          cout<<wrong;
          return 0;
      }
      int biggestLegacy=0;
      string fatherOfAll="Kru6a";
      int maxLegacy=0;
      for(int i=0;i<fathers.size();i++)
      {
          if(legacies[fathers[i]]==0&&isFather[fathers[i]])
          {
              FindAncestors(fathers[i]);
          }
            if(legacies[fathers[i]]>maxLegacy)
            {
                fatherOfAll=fathers[i];
                maxLegacy=legacies[fathers[i]];
            }
            else if(legacies[fathers[i]]==maxLegacy&&fathers[i]>fatherOfAll)
            {
                fatherOfAll=fathers[i];
            }
      }
      cout<<fatherOfAll;
      for(int i=0;i<fathers.size();i++)
      {
          cout<<"\n"<<fathers[i]<<" "<<legacies[fathers[i]];
      }
    }
    void FindAncestors(string father)
    {
        for(int i=0;i<arr[father].size();i++)
        {
            if(isFather[arr[father][i]]==false)
            {
                legacies[father]++;
            }
            else if(legacies[arr[father][i]]!=0)
            {
                legacies[father]+=legacies[arr[father][i]];
            }
            else
            {
               FindAncestors(arr[father][i]);
            }
        }
    }
