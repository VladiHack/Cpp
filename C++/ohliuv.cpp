#include <iostream>
using namespace std;

const int N=1002;
int a[N];
int n;

int main()
{
  ios_base::sync_with_stdio(false);
  while(cin >> n)
  {
        int ts = 0;
  for(int i=0;i<n;i++) {cin >> a[i];ts += a[i];}

  int T = ts / 2 + 1;
  bool d[T], c[T];
  for (int i = 0; i < T; i++) d[i] = c[i] = false;
  d[0] = true;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j + a[i] < T; j++)
     if (d[j]) c[j + a[i]] = true;

    for (int j = 0; j < T; j++)
     {if (c[j]) d[j] = true; c[j] = false;}
  }

  for (int i = T - 1; i >= 0; i--)
   if (d[i])
    {
        int minimum=min(i,ts-i);
        cout<<minimum<<"\n";
        break;
   }

  }

}
