#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int val){
    stack<int> temp;
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(val);
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
}

void insertAtBottom_Recursion(stack<int> &st, int val){
    if (st.empty()){
        st.push(val);
        return;
    }
    int curr = st.top();
    st.pop();
    insertAtBottom_Recursion(st, val);
    st.push(curr);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    insertAtBottom(st,10);
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }
    
    return 0;
}