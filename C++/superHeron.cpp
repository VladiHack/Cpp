    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
      long long int  a;int b;int c;
      int half;long long int s;int R;int r; int p;
      unordered_map<int,vector<int>> triples;
      int countTriples=0;
    int main()
    {
      ios_base::sync_with_stdio(false);
        cin.tie(NULL);
      cin>>p;
      half=p/2;
      if(p%2==1)
      {
          cout<<0;
          return 0;
      }
      long long int results=0;
      int getBiggest=0;
      for(int i=half;i>=1;i--)
      {
          a=i;
          for(int k=half;k>=1;k--)
          {
              b=k;
              c=p-a-b;
              getBiggest=a;
              if(b>getBiggest)
              {
                  getBiggest=b;
              }
              if(c>getBiggest)
              {
                  getBiggest=c;
              }
              if(a+b>c&&b+c>a&&a+c>b)
              {
                   s=half*(half-a)*(half-b)*(half-c);
                   long long int korenche=sqrt(s);
                   int kopirai=korenche;
                   korenche*=korenche;
                   if(s==korenche)
                   {
                       korenche=kopirai;
                       if(korenche%half==0)
                       {
                           a*=b*c;
                           korenche*=4;
                           if(a%korenche==0)
                           {
                               int biggest=max(i,c);
                               biggest=max(biggest,k);
                               int smallest=min(k,c);
                               smallest=min(i,smallest);
                               int avg=i+k+c-biggest-smallest;
                               bool met=false;
                              for(int j=0;j<countTriples;j++)
                              {
                                  if(triples[j][0]==biggest&&triples[j][1]==avg&&triples[j][2]==smallest)
                                  {
                                      met=true;
                                      break;
                                  }
                              }
                              if(!met)
                              {
                                results++;
                              triples[countTriples].push_back(biggest);
                              triples[countTriples].push_back(avg);
                              triples[countTriples].push_back(smallest);
                              countTriples++;
                              }
                           }
                       }
                   }
              }
          }
      }
      cout<<results;
    }
