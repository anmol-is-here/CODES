#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverse_qu(queue<int> &qu){
    stack<int> st;
    while(!qu.empty()){
        st.push(qu.front());
        qu.pop();
    }
    while(!st.empty()){
        qu.push(st.top());
        st.pop();
    }
    return;
}


int main() {
    queue<int> input;
    input.push(10);
    input.push(20);
    input.push(30);
    input.push(40);
    reverse_qu(input);
    while(!input.empty()){
        cout<<input.front()<<" ";
        input.pop();
    } cout<<endl;
    
    return 0;
}