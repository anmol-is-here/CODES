#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool isBalance(string str){
    stack<char> st;

    for(int i = 0; i<str.size(); i++){
        char ch = str[i];
        if(ch == '{' or ch=='[' or ch=='('){
            st.push(ch);
        }
        else {
            if(ch == '}' and !st.empty() and st.top()=='{'){
                st.pop();
            }
            else if(ch == ']' and !st.empty() and st.top()=='['){
                st.pop();
            }
            else if(ch == ')' and !st.empty() and st.top()=='('){
                st.pop();
            }
            else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string str  {"({[(){[][]}]}{)"};
    cout<<isBalance(str);
    
    return 0;
}