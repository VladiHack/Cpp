// C++ program to print all combination
// of size r in an array of size n
#include<bits/stdc++.h>
using namespace std;
 long long int countSums=0;
 int a=0;int b=0;
void combinationUtil(int arr[], int data[],
                    int start, int end,
                    int index, int r,int sum);

void printCombination(int arr[], int n, int r,int sum)
{
    int data[r];
    combinationUtil(arr, data, 0, n-1, 0, r,sum);
}

void combinationUtil(int arr[], int data[],
                    int start, int end,
                    int index, int r,int sum)
{
    // Current combination is ready
    // to be printed, print it
    if (index == r||sum>b)
    {
        if(sum<=b)
        {
            countSums++;
        }
        return;
    }
    for (int i = start; i <= end &&
        end - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1,
                        end, index+1, r,sum+data[i]);
    }
}

// Driver code
int main()
{
    int n;
    cin>>n>>a>>b;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    printCombination(arr, n, n,0);
    cout<<countSums;
}
