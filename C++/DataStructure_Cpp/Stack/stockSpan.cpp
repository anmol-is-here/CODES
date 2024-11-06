/**
 * Question -> Given a series of N daily price quotes for a stock and we need to calculate the span of the stock’s price for all N days. 
 * The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, 
 * for which the price of the stock on the current day is less than its price on the given day. 
 * 
 * Example -> Input: N = 7, price[] = [100 80 60 70 60 75 85]
 *            Output: 1 1 1 2 1 4 6
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector <int> pge(vector<int> &arr){ // functioin to calculate next gratest element.
    int n = arr.size();
    reverse(arr.begin(), arr.end());
    vector<int> output(n, -1);
    stack<int> st;
    st.push(0);
    for(int i=1; i<n; i++){
        while(!st.empty() and arr[i] >= arr[st.top()]) {
            output[st.top()] = n-i-1; // because after reverse the indexes will change.
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){  // not mendetory while loop.
        output[st.top()] = -1;
        st.pop();
    }
    reverse(output.begin(), output.end());
    reverse(arr.begin(), arr.end());

    return output;
}


int main() {
    vector<int> v {100, 80, 60, 70, 60, 75, 85};
    vector<int> res = pge(v);
    for(int i = 0; i<res.size(); i++){
        cout<<i - res[i]<<" ";
    }
    
    return 0;
}