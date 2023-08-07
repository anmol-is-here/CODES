#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> qu, temp;
    MyStack() {
        
    }
    
    void push(int x) {
        qu.push(x);
        
    }
    
    int pop() {
        while(qu.size()>1){
            int x = qu.front();
            qu.pop();
            temp.push(x);
        }
        int element = qu.front();
        qu.pop();        
      
        while(!temp.empty()){
            int y = temp.front();
            // cout<<y<<"*";
            temp.pop();
            qu.push(y);
        }

        return element;
        
    }
    
    int top() {
        while(qu.size()>1){
            temp.push(qu.front());
            qu.pop();
        }
        int element = qu.front();
        temp.push(element);
        qu.pop();
        while(!temp.empty()){
            qu.push(temp.front());
            temp.pop();
        }
        return element;
    }
    
    bool empty() {
        return qu.empty();
        
    }
};

int main() {
    
    MyStack st;
    st.push(1);    
    st.push(2);     
    st.pop();

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    } cout<<endl;

    return 0;
}