#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, count = 1, z, max = 0;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if ((abs(arr[i] - arr[j]) == 1) || (arr[i] == arr[j])) {
                ++count;
            }
            else {
                z = count;
                count = 0;
                break;
            }
        }
        if (max < z) {
        max = z;
    }
    }
    cout<<max<<endl;
}