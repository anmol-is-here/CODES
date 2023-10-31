//  https://cses.fi/problemset/task/1636


#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007

vector<int> dp(1000005, 0);

int fbu(vector<int> &coin, int x, int n){
    
    dp[0] = 1;
    
    for(int j = 0; j < n; j++){
        // go to each coin.
        for(int i = 1; i <= x; i++){
            if(i - coin[j] < 0) continue;
            dp[i] = (dp[i] % MOD + dp[i - coin[j]] % MOD) % MOD;
        }
    }
    return dp[x];

}

int main() {

    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int> coin(n);
    for(int i = 0; i < n; i++) cin>>coin[i];

    cout<<fbu(coin, x, n)<<endl;
    
    return 0;
}