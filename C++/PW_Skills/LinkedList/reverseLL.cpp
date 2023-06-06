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

Node* reverseLL(Node* &head) {
    Node* current = head;
    Node* prev = NULL;

    while(current!=NULL) {
        Node* Next = current->next;
        current->next = prev;
        prev = current;
        current = Next;
    }
    // when this loop ends, prev pointing to my last node which is new head.
    Node* new_head = prev;
    return new_head;
}

Node* reverseLLRecursive(Node* &head) {
    // base case.
    if(head == NULL or head->next == NULL) {
        return head;
    }

    // recursive case.
    Node* new_head = reverseLLRecursive(head->next);
    head->next->next = head;
    head->next = NULL; // head is now pointing to last node in our reversed ll.
    return new_head;
}

int main() {
    LinkedList ll;
    for (int i = 1; i<=5; i++){
        ll.insertAtTail(i);
    }
    ll.display();
    ll.head = reverseLL(ll.head);
    ll.display();
    ll.head = reverseLLRecursive(ll.head);
    ll.display();
    
    return 0;
}