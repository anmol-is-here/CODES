#include<iostream>
#include<vector>
using namespace std;

void countSort(vector <int> &v, int pos) {
    int n = v.size();

    //create a frequincy array

    vector <int> freq(10, 0);
    for (int i = 0; i<n; i++){
        freq[(v[i]/pos)%10]++;
    }

    // calculate cumilative frequency

    for (int i = 1; i<10; i++){
        freq[i] += freq[i-1];
    }

    vector <int> ans(n);
    for (int i = n-1; i>=0; i--){
        ans[--freq[(v[i]/pos)%10]]= v[i];
    }

    // copy the answer array to original array
    for (int i=0; i<n; i++){
        v[i] = ans[i];
    }
}

void radixSort(vector <int> &v){

    int max_ele = INT16_MIN;
    for(auto x: v) {
        max_ele = max(x,max_ele);
    }

    for (int pos = 1; max_ele/pos>0; pos *= 10) {
        countSort(v, pos);
    }
}

int main() {
    int n;
    cin>>n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    radixSort(a);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";

    }
    cout<<endl;
    
    
    return 0;
}