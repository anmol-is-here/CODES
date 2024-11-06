#include <iostream>
#include <vector>
// #include <string>
using namespace std;

class Node{
public:
    int val;
    Node* prev;
    Node* next;

    Node(int data) {
        val = data;
        prev = NULL;
        next = NULL;
    }
};

class Double_LinkedList{
public:
    Node* head;
    Node* tail;

    Double_LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtHead(int val) {
        Node* new_node = new Node(val);

        if (head == NULL){
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return;
    }

    void insertAtTail(int val) {
        Node* new_node = new Node(val);

        if (head == NULL){
            head = new_node;
            tail = new_node;
            return;
        }

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        return; 
    }

    void insertAtPosition(int val, int k){
        // assuming k is less than or equal to the length of doubly linked list.

        Node* new_node = new Node(val);
        Node* temp = head;

        int counter {k-1};  // work on zero based indexing
        while(counter--){
            temp = temp->next;
        }

        new_node->next = temp->next;
        temp->next = new_node;

        new_node->prev = temp;
        new_node->next->prev = new_node;
        return;
    }

    void deleteAtHead(){
        if (head == NULL){
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head == NULL){ // if doubly linked list had only 1 node.
            tail = NULL;
        }
        else{
        head->prev = NULL;
        }

        delete temp;
        return;
    }

    void deleteAtTail(){
        if (tail == NULL) {
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if (tail == NULL) {
            head = NULL;
        }
        else {
        tail->next = NULL;
        }

        delete temp;
        return;
    }

    void deleteAtPosition(int k) {
        Node* temp = head;
        int counter {0}; // work on zero based indexing.

        while(counter != k-1){
            temp = temp->next;
            counter++;
        }

        Node* temp1 = temp->next; // node to be deleted.
        temp->next = temp1->next;
        temp1->next->prev = temp;
        delete temp1;
        return;
    }

    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
    Double_LinkedList dll;
    dll.insertAtHead(1);
    dll.insertAtHead(2);
    dll.insertAtHead(3);
    dll.insertAtHead(4);
    dll.display();
    dll.insertAtTail(5);
    dll.display();
    dll.insertAtPosition(20,3);
    dll.display();
    dll.deleteAtHead();
    dll.display();
    dll.deleteAtTail();
    dll.display();
    dll.deleteAtPosition(2);
    dll.display();
    
    return 0;
}