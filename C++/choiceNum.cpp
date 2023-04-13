#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n);
    
    int count = 0, count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1) {
            count++;
        }
        else if (arr[i] == 2)
        {
            count_1++;
        }
        else if (arr[i] == 3)
        {
            count_2++;
        }
        else if (arr[i] == 4)
        {
            count_3++;
        }
        else
        {
            count_4++;
        }
    }
    cout<<count<<count_1<<count_2<<count_3<<count_4;
  
} 