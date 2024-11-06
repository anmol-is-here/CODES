#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> copyStack(stack<int> &input) {
    stack<int> temp;
    while(!input.empty()) {
        int curr = input.top();
        input.pop();
        temp.push(curr);
    }
    stack<int> result;
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        result.push(curr);
    }
    return result;
}

void copyStack_Recursion(stack<int> &st, stack<int> &result){
    if (st.empty()){
        return;
    }
    int curr = st.top();
    st.pop();
    copyStack_Recursion(st,result);
    result.push(curr);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // stack<int> res = copyStack(st);
    stack<int> res;
    copyStack_Recursion(st,res);
    while(!res.empty()){
        int curr = res.top();
        res.pop();
        cout<<curr<<endl;
    }
    
    return 0;
}