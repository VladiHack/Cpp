    #include <iostream>
    using namespace std;

    int main()
    {
         ios_base::sync_with_stdio(false);
        cin.tie(NULL);
     int t;
     cin>>t;
     for(int i=0;i<t;i++)
     {
         int n;
         cin>>n;
         int arr[n];
         for(int i=0;i<n;i++)
         {
             cin>>arr[i];
         }
         int queries;
         cin>>queries;
         for(int z=0;z<queries;z++)
         {
             int start;int res;
             cin>>start>>res;
             start--;
             long long int resByFar=arr[start];
             int indexFin=-2;
             if(resByFar>=res)
             {
                 indexFin=start;
             }
             for(int s=start+1;s<n;s++)
             {
                 resByFar&=arr[s];
                 if(resByFar>=res)
                 {
                     indexFin=s;
                 }
                 else if(resByFar==0)
                 {
                     break;
                 }
             }
             cout<<indexFin+1<<" ";
         }
         cout<<"\n";

     }

    }
