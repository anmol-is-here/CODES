#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main() {
    int num;
    cin>>num;
    while (num-->0){
        int ans,n = 3;
        vector <int> v;
        for (int i = 0; i<n; i++) {
            int ele;
            cin>>ele;
            v.push_back(ele);
        }
        int max = *max_element(v.begin(), v.end());
        int min = *min_element(v.begin(), v.end());
        for (int i = 0; i<n; i++) {
            if (v[i] == max || v[i] == min) {
                continue;
            }
            else {
                ans = v[i];
                cout<<ans<<endl;
            }
        }
 
    }
    return 0;
}