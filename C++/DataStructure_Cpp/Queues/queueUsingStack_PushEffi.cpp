#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Queue{
    stack<int> st;
public:
    Queue(){}

    void push(int val){
        /**
         * Time: O(1)
        */
        st.push(val);
    }

    void pop(){
        /**
         * Time: O(n)
        */
        stack<int> temp;
        while(st.size() > 1){
            int curr = st.top();
            st.pop();
            temp.push(curr);
        }
        st.pop();
        while(!temp.empty()){
            int curr = temp.top();
            temp.pop();
            st.push(curr);
        }
    }

    bool empty(){
        return st.empty();
    }

    int front(){
        /**
         * Time: O(n)
        */
       stack<int> temp;
        while(st.size() > 1){
            int curr = st.top();
            st.pop();
            temp.push(curr);
        }
        int show = st.top();
        while(!temp.empty()){
            int curr = temp.top();
            temp.pop();
            st.push(curr);
        }
        return show; 
    }
};

int main() {
    Queue qu;
    qu.push(10);    
    qu.push(20);    
    qu.push(30);    
    qu.push(40);    
    qu.pop();
    qu.pop();

    while(!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    } cout<<endl;
    
    return 0;
}