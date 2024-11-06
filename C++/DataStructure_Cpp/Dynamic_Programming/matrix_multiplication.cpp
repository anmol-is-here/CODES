#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

vector<vector<int>> dp;

int f(int i, int j, vector<int> &arr){
    if(i == j or i+1 == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    for(int k = i+1; k < j; k++){
        ans = min(ans, f(i, k, arr) + f(k, j, arr) + arr[i]*arr[k]*arr[j]);
    }
    return dp[i][j] = ans;
}

int main() {

    int n;
    cin>>n;
    vector<int> arr(n);
    dp.clear();
    dp.resize(1005, vector<int>(1000, 0));
    for(int i = 0; i < n; i++) cin>>arr[i];

    for(int len = 3; len <= n; len++){
        for(int i = 0; i + len - 1 < n; i++){
            int j = i + len - 1;  // last index of array.
            dp[i][j] = INT_MAX;
            for(int k = i+1; k < j; k++){
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j]);
            }
        }
    }
    
    // cout<<f(0, n-1, arr)<<endl;
    cout<<dp[0][n-1]<<endl;
    return 0;
}