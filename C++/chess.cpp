            #include <iostream>
            #include <bits/stdc++.h>
            using namespace std;
            int main()
            {
             unordered_map<char,int> convertToDigit;
             convertToDigit['a']=1;
             convertToDigit['b']=2;
             convertToDigit['c']=3;
             convertToDigit['d']=4;
             convertToDigit['e']=5;
             convertToDigit['f']=6;
             convertToDigit['g']=7;
             convertToDigit['h']=8;
             int pawnsAttacked=0;
                vector<string> coordinates;
               string s;
               while(getline(cin,s))
               {
                   if(s=="break")
                   {
                       break;
                   }
                   coordinates.push_back(s);
               }
               int arr[9][9];
               memset(arr,0,sizeof(arr));
               for(int i=0;i<coordinates.size()-2;i++)
               {
                   int convertedBukva=convertToDigit[coordinates[i][0]];
                   int y=(coordinates[i][1]-'0');
                   arr[convertedBukva][y]=1;
               }
               bool met[9][9];
               memset(met,false,sizeof(met));
               for(int i=coordinates.size()-2;i<coordinates.size();i++)
               {
                     int x=convertToDigit[coordinates[coordinates.size()-2][0]];
                     int y=coordinates[i][1]-'0';
                     //Fixiram x i vurvq nagore
                     for(int row=x-1;row>0;row--)
                     {
                         if(arr[row][y]==1&&met[row][y]==false)
                         {
                             met[row][y]=true;
                             pawnsAttacked++;
                         }
                         if(arr[row][y]==1)
                         {
                             break;
                         }
                     }
                     for(int row=x+1;row<9;row++)
                     {
                          if(arr[row][y]==1&&met[row][y]==false)
                         {
                             met[row][y]=true;
                             pawnsAttacked++;
                         }
                         if(arr[row][y]==1)
                         {
                             break;
                         }
                     }
                     for(int col=y-1;col>0;col--)
                     {
                         if(arr[x][col]==1&&met[x][col]==false)
                         {
                             met[x][col]=true;
                             pawnsAttacked++;
                         }
                         if(arr[x][col]==1)
                         {
                             break;
                         }
                     }
                     for(int col=y+1;col<9;col++)
                     {
                         if(arr[x][col]==1&&met[x][col]==false)
                         {
                             met[x][col]=true;
                             pawnsAttacked++;
                         }
                         if(arr[x][col]==1)
                         {
                             break;
                         }

                     }
                     int copyX=x-1;int copyY=y-1;
                     while(copyX>=1&&copyY>=1)
                     {
                         if(arr[copyX][copyY]==1&&met[copyX][copyY]==false)
                         {
                             met[copyX][copyY]=true;
                             pawnsAttacked++;
                         }
                         if(arr[copyX][copyY]==1)
                         {
                             break;
                         }
                         copyX--;copyY--;
                     }
                     copyX=x+1;copyY=y+1;
                     while(copyX<=8&&copyY<=8)
                     {
                         if(arr[copyX][copyY]==1&&met[copyX][copyY]==false)
                         {
                             met[copyX][copyY]=true;
                             pawnsAttacked++;
                         }
                         if(arr[copyX][copyY]==1)
                         {
                             break;
                         }
                         copyX++;copyY++;
                     }
                     copyX=x+1;copyY=y-1;
                     while(copyX<=8&&copyY>=1)
                     {
                        if(arr[copyX][copyY]==1&&met[copyX][copyY]==false)
                         {
                             met[copyX][copyY]=true;
                             pawnsAttacked++;
                         }
                         if(arr[copyX][copyY]==1)
                         {
                             break;
                         }
                         copyX++;copyY--;
                     }
                     copyX=x-1;copyY=y+1;
                     while(copyX>=1&&copyY<=8)
                     {
                        if(arr[copyX][copyY]==1&&met[copyX][copyY]==false)
                         {
                             met[copyX][copyY]=true;
                             pawnsAttacked++;
                         }
                         if(arr[copyX][copyY]==1)
                         {
                             break;
                         }
                         copyX--;copyY++;
                     }
               }
               cout<<pawnsAttacked;
            }
