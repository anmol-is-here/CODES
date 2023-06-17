/**
 * Question -> Given an array og integer heights representing the histogram's bar height where the width of each bar is 1,
 *  return the area of largest rectangle in the histogram.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int histogram(vector<int> &arr){
    int n = arr.size();
    int ans = INT16_MIN;
    stack<int> st;
    st.push(0);
    for(int i=1; i<n; i++){
        while(!st.empty() and arr[i] < arr[st.top()]) {
            int ele = arr[st.top()]; // current bar to be removed and whose answer to be calculated.
            st.pop();
            int nsi = i;
            int psi = (st.empty()) ? (-1) : st.top();
            ans = max(ans, ele*(nsi-psi-1));
        }
        st.push(i);
    }
    while(!st.empty()){
        int ele = arr[st.top()];
        st.pop();
        int nsi = n;
        int psi = (st.empty()) ? (-1) : st.top();
        ans = max(ans, ele*(nsi-psi-1));
    }   
    return ans;
}

int main() {
    vector<int> v {2,1,5,6,2,3,0,2,1,5,6,2,3};
    int ans = histogram(v);
    cout<<ans;
    
    return 0;
}