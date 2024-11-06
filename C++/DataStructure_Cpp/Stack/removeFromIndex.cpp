#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void insertAtIndex(stack<int> &st, int idx){
    int position_to_pop = st.size()-idx-1;
    int out_ele = 0;
    if(out_ele == position_to_pop){
        st.pop();
        return;
    }
    int curr = st.top();
    st.pop();
    out_ele++;
    insertAtIndex(st, idx);
    st.push(curr);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    insertAtIndex(st, 2);
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }
    
    return 0;
}