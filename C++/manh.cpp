#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
   int x1;int x2;int y1;int y2;
   int a1;int a2;int b1;int b2;
   cin>>x1>>y1>>x2>>y2;
   cin>>a1>>b1>>a2>>b2;
   int sum1=0;
   int sum2=0;
   int sum3=0;
   int sum4=0;
   int left=0;
   int right=0;
   int up=0;
   int down=0;
  if(x1==x2)
  {
      if(a1==a2)
      {
            up=max(y1,y2);
            down=y1+y2-up;
           if(b1>=down&&b1<=up||b2>=down&&b2<=up)
           {
                  cout<<abs(x1-a1);
           }

           else
           {
           sum1=abs(y1-b1);
            sum2=abs(y1-b2);
            sum3=abs(y2-b1);
            sum4=abs(y2-b2);
            int result=sum1;
            result=min(result,sum2);
            result=min(result,sum3);
            result=min(result,sum4);
            cout<<abs(x1-a1)+result;
          }

      }
      else
      {
        //x1==x2   b1==b2
        up=max(y1,y2);
        down=y1+y2-up;
        left=min(a1,a2);
        right=a1+a2-left;
        int result=0;
        if(b1<down||b1>up)
        {
            result+=min(abs(b1-down),abs(b1-up));
        }
        if(x1<left||x1>right)
        {
            result+=min(abs(x1-left),abs(x1-right));
        }
        cout<<result;
      }

  }
  else
  {
      if(b1==b2)
      {
           left=min(x1,x2);
           right=x1+x2-left;
          if(left<=a1&&a1<=right||left<=a2&&a2<=right)
          {
                      cout<<abs(y1-b1);
          }
          else
          {
           sum1=abs(x1-a1);
            sum2=abs(x1-a2);
            sum3=abs(x2-a1);
            sum4=abs(x2-a2);
            int result=sum1;
            result=min(result,sum2);
            result=min(result,sum3);
            result=min(result,sum4);
            cout<<abs(y1-b1)+result;
          }

      }
      else
      {
        //a1==a2  y1==y2
        up=max(b1,b2);
        down=b1+b2-up;
        left=min(x1,x2);
        right=x1+x2-left;
        int result=0;
        if(y1<down||y1>up)
        {
            result+=min(abs(y1-down),abs(y1-up));
        }
        if(a1<left||a1>right)
        {
            result+=min(abs(a1-left),abs(a1-right));
        }
        cout<<result;
      }

  }

}
