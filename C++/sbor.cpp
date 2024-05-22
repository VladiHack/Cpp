    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
       string num;
       cin>>num;
       sort(num.begin(),num.end());
       int countZeros=0;
       int zeroEnds=0;
       for(int i=0;i<num.size();i++)
       {
           if(num[i]=='0')
           {
               countZeros++;
           }
           else
           {
               zeroEnds=i;
            break;
           }
       }
       char firstDif=' ';bool addedZeros=false;
       string smallest="";
       for(int i=zeroEnds;i<num.size();i++)
       {
         if(firstDif==' ')
         {
             firstDif=num[i];
         }
         else if(addedZeros==false)
         {
             for(int s=0;s<countZeros;s++)
             {
                 smallest+='0';
             }
             addedZeros=true;
         }
        smallest+=num[i];
       }
       if(addedZeros==false)
       {
           for(int s=0;s<countZeros;s++)
             {
                 smallest+='0';
             }
       }
       reverse(num.begin(),num.end());
       string sum = std::to_string(std::stol(smallest) + std::stol(num));
       cout<<sum;
    }
