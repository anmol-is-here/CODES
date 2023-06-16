#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector <int> nge(vector<int> &arr){ // functioin to calculate next gratest element.
    int n = arr.size();
    vector<int> output(n, -1);
    stack<int> st;
    st.push(0);
    for(int i=1; i<n; i++){
        while(!st.empty() and arr[i] > arr[st.top()]) {
            output[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){  // not mendetory while loop.
        output[st.top()] = -1;
        st.pop();
    }
    return output;
}

vector <int> nse(vector<int> &arr){ // function to calculate next smaller element.
    int n = arr.size();
    vector<int> output(n, -1);
    stack<int> st;
    st.push(0);
    for(int i=1; i<n; i++){
        while(!st.empty() and arr[i] < arr[st.top()]) {
            output[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){  // not mendetory while loop.
        output[st.top()] = -1;
        st.pop();
    }   
    return output;
}

int main() {
    vector<int> v {4,6,3,1,0,9,5,6,7,3};
    vector<int> res = nse(v);
    for(int i = 0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    
    return 0;
}