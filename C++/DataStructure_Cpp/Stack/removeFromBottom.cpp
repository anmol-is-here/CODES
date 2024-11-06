#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void removeFromBottom(stack<int> &st){
    if (st.size()==1){
        st.pop();
        return;
    }
    int curr = st.top();
    st.pop();
    removeFromBottom(st);
    st.push(curr);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    removeFromBottom(st);
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }
    
    return 0;
}