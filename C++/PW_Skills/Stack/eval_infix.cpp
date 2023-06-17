#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

int calc(int v1, int v2, char op) {
    if(op == '^'){
        return pow(v1,v2);
    }
    if(op == '+'){
        return v1 + v2;
    }
    if(op == '*'){
        return v1*v2;
    }
    if(op == '/') {
        return v1/v2;
    }
    else {
        return v1 - v2;
    }
}

int precedance (char op) {
    if(op == '^') {
        return 3;
    }
    else if(op == '*' or op == '/') {
        return 2;
    }
    else if(op == '+' or op == '-'){
        return 1;
    }
    else return -1;
}

int eval(string str){
    stack<int> num;
    stack<char> op;
    for(int i = 0; i<str.size(); i++) {
        if(isdigit(str[i])){
            num.push(str[i] - '0');
        }
        else if(str[i] == '('){
            op.push(str[i]);
        }
        else if(str[i] == ')'){
            while(!op.empty() and op.top() != '('){
                char ops = op.top();
                op.pop();

                int v2 = num.top();
                num.pop();
                int v1 = num.top();
                num.pop();
                num.push(calc(v1, v2, ops));
            }
            // op stack top contains element '(' so we need to pop it.
            if(!op.empty()){
                op.pop();
            }
        }
        // now only we need to push operators and calculate their result taking care of precedence order
        else{
            while(!op.empty() and precedance(op.top()) >= precedance(str[i])) {
               char ops = op.top();
                op.pop();

                int v2 = num.top();
                num.pop();
                int v1 = num.top();
                num.pop();
                num.push(calc(v1, v2, ops));  
            }
            // element found is of grater precedence so we need to push it to op stack.
            op.push(str[i]);
        }
    }
    // still op stack is not empty and it contains some of the operators.
    while(!op.empty()){
        char ops = op.top();
        op.pop();

        int v2 = num.top();
        num.pop();
        int v1 = num.top();
        num.pop();
        num.push(calc(v1, v2, ops));
    }
    return num.top();
}

int main() {
    string str {"1+(2*(3-1))+2"};
    cout<<eval(str)<<endl;
    
    return 0;
}