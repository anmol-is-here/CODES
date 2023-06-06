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

class LinkedList{
public:
    Node* head;
    LinkedList(){
        head = NULL;
    }

    void insertAtTail(int value) {
        Node* new_node = new Node(value);
        if(head == NULL) { // Linked List is empty.
            head = new_node;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }    
};

Node* reverseK_nodes(Node* head, int k) {
    
    Node* preptr = NULL;
    Node* currptr = head;
    int counter {0}; // for counting first k nodes.

    while(currptr!=NULL and counter<k) { // reverse first k nodes.
        Node* nextptr = currptr->next;
        currptr->next = preptr;
        preptr = currptr;
        currptr = nextptr;
        counter++;
    }

    // currptr will give us (k+1)th node.
    if(currptr!=NULL) {
        Node* new_node = reverseK_nodes(currptr, k);
        head->next = new_node;
    }
    return preptr; // preptr will give the new_hwad of connected LinkedList.
}

int main() {
    LinkedList ll;
    for (int i = 1; i<=6; i++){
        ll.insertAtTail(i);
    }
    ll.display();

    ll.head = reverseK_nodes(ll.head, 2);
    ll.display();

    return 0;
}