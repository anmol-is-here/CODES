#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int
using namespace std;

bool cmp(int x, int y){
    return x > y;
}

ll minCostToBreakGrid(int m, int n, vector<int> &vertical, vector<int> &horizontal){
    sort(vertical.begin(), vertical.end(), cmp);
    sort(horizontal.begin(), horizontal.end(), cmp);
    int hz = 1;
    int vr = 1; 
    int v = 0, h = 0;
    ll ans = 0;
    while(v < vertical.size() and h < horizontal.size()){
        if(vertical[v] > horizontal[h]){
            ans += vertical[v]*vr;
            hz++;
            v++;
        }
        else{
            ans += horizontal[h]*hz;
            vr++;
            h++;
        }
    }
    while(vertical[v] > horizontal[h]){
        ans += vertical[v]*vr;
        hz++;
        v++;
    }
    while(vertical[v] < horizontal[h]){
        ans += horizontal[h]*hz;
        vr++;
        h++;
    } 
    return ans;
}

int main() {
    int m = 6, n = 4;
    vector<int> X {2,1,3,1,4};
    vector<int> Y {4,2,1};
    cout<<minCostToBreakGrid(m, n, X, Y);
    
    return 0;
}