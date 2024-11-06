#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void insertAtIndex(stack<int> &st, int idx, int val){
    int position_to_insert = st.size()-idx;
    int out_ele = 0;
    if(out_ele == position_to_insert){
        st.push(val);
        return;
    }
    int curr = st.top();
    st.pop();
    out_ele++;
    insertAtIndex(st, idx, val);
    st.push(curr);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    insertAtIndex(st, 0, 10);
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }
    
    return 0;
}