#include<iostream>
#include<vector>
using namespace std;

void totalPrefixSum(vector <int> &v) {
    for (int i = 1; i<=v.size(); i++) {
        v[i] += v[i-1];
    }
    return;
}

bool checkPrifixSuffixSum(vector<int> &v) {
    
    int total_sum  = 0;
    // total_sum = totalPrefixSum(v);
    for (int i = 0; i<v.size(); i++) {
        total_sum += v[i];
    }
    // cout<<"total sum : "<<total_sum<<endl;

    int prifix_sum = 0;
    for (int i = 0; i<v.size(); i++) {
        prifix_sum += v[i];
        int suffix_sum = total_sum - prifix_sum;
        // cout<<"total sum : "<<total_sum<<endl;
        // cout<<"suffix sum : "<<suffix_sum<<endl;
        if (suffix_sum == prifix_sum) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin>>n;

    // 0 based indexing.
    // vector <int> v;

    // for (int i = 0; i<n; i++ ){
    //     int ele;
    //     cin>>ele;
    //     v.push_back(ele);
    // }

    // 1 based indexing.
    vector <int> v(n+1, 0);

    for(int i=1; i<=n; i++) {
        cin>>v[i];
    }

    int q;
    cout<<"No. of query : ";
    cin>>q;
    totalPrefixSum(v);

    while (q--) {
        int l, r;
        cin>>l>>r;
        cout<<v[r]-v[l-1]<<endl;
    }
    // cout<<totalPrefixSum(v)<<endl;
    // cout<<checkPrifixSuffixSum(v)<<endl;

    // for (int i = 0; i<n; i++ ){
    //     cout<<v[i]<<" ";
    // } 
    // cout<<endl;
    return 0;
}