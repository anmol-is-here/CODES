#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector <int> > result;

void f(vector<int> &c, int idx, int t, vector<int> &v){
    if(t == 0){
        result.push_back(v);
        return;
    }
    if(idx == c.size()) return;
    if(c[idx] <= t){
        // we can pick.
        v.push_back(c[idx]);
        f(c, idx, t-c[idx], v);
        v.pop_back();
    }
    // for excluding the elements.
    int j = idx+1; 
    f(c, j, t, v);
}

vector<vector<int>> combinationSum2(vector<int>& c, int target) {
    result.clear();
    sort(c.begin(), c.end());
    vector<int> v;
    f(c, 0, target, v);
    return result;
}

int main(){

}