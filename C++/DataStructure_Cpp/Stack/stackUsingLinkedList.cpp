#include <iostream>
#include <vector>
// #include <string>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int data){
        val = data;
        next = NULL;
    }
};

class Stack{
    Node* head;
    int capacity;
    int currsize;
    public:
    Stack(int c){
        capacity = c;
        currsize = 0;
        head = NULL;
    }

    bool isEmpty(){
        return head == NULL;
    }

    bool isFull(){
        return currsize == capacity;
    }

    void push(int data){
        Node* new_node = new Node(data);
        if(currsize == capacity){
            cout<<"Overrflow\n";
            return;
        }
        new_node->next = head;
        head = new_node;
        currsize++;
    }

    int pop(){
        if(head == NULL){
            cout<<"Underflow\n";
            return INT16_MIN;
        }
        Node* new_head = head->next;
        head->next = NULL;
        Node* tobeRemoved = head;
        int result = tobeRemoved->val;
        head = new_head;
        delete tobeRemoved;
        currsize--;
        return result;
    }

    int getTop(){
        if(head == NULL){
            cout<<"Underflow\n";
            return INT16_MIN;
        }
        return head->val;
    }

    int size(){
        return currsize;
    }
};

int main() {
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.getTop()<<endl;
    st.push(4);
    st.push(5);
    cout<<st.getTop()<<endl;
    st.push(6);
    
    st.pop();
    st.pop();
    cout<<st.getTop()<<endl;
    
    return 0;
}