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
        next =  NULL;
    }
};

class Queue{
    Node* head;
    Node* tail;
    int size;
public:
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void enqueue(int data){ // this operation requires insertion at tail.
        Node* newNode = new Node(data);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void dequeue(){ // this operation requires removal from head.
        if(head == NULL){
            return;
        }
        else{
            Node* temp = head;
            head = head->next;
            if(head == NULL){
                tail = NULL;
            }
            temp->next = NULL;
            delete temp;
            size--;
        }
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return head == NULL;
    }

    int front(){
        if(head == NULL) {
            return -1;
        }
        return head->val;

    }
};

int main() {
    Queue qu;
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.dequeue();
    qu.enqueue(40);

    while(!qu.isEmpty()){
        cout<<qu.front()<<" ";
        qu.dequeue();
    } cout<<endl;
    
    return 0;
}