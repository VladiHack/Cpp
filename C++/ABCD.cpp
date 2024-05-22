    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    int workers;int minimalPayment;
    int minWage=INT_MAX;
    vector<vector<int>> employees(5001);
    void TestCombos(int arr[],int employeeNumber,int sumWages)
    {
        if(minWage<=sumWages)
        {
            return;
        }
        if(employeeNumber==workers+1)
        {
            minWage=sumWages;
            return;
        }
        for(int i=0;i<employees[employeeNumber].size();i++)
        {
            int boss=employees[employeeNumber][i];
            arr[boss]+=arr[employeeNumber];
            TestCombos(arr,employeeNumber+1,sumWages+arr[employeeNumber]);
            arr[boss]-=arr[employeeNumber];
        }
    }
    int main()
    {
        cin>>workers>>minimalPayment;
        for(int i=0;i<workers;i++)
        {
            int wishes;int num;
            cin>>wishes;
            for(int k=0;k<wishes;k++)
            {
                cin>>num;
                employees[i+1].push_back(num);
            }
        }
        int arr [workers+1];
        memset(arr,minimalPayment,sizeof(arr));
        TestCombos(arr,1,workers*minimalPayment);
        cout<<minWage;
    }
