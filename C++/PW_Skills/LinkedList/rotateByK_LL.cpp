/**
 * Question -> Rearrange the nodes in a list - Given the head of a linked list, rotate the list to right by k places.
*/

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
        Node* tail = head;
        while(tail->next!=NULL){
            tail = tail->next;
        }
        tail->next = new_node;
    }
    void display(){
        Node* tail = head;
        while(tail!=NULL){
            cout<<tail->val<<"->";
            tail = tail->next;
        }
        cout<<"NULL"<<endl;
    }    
};

Node* rotateByK(Node* &head, int k) {
    // 1. find number of nodes.
    int n {0}; 
    Node* tail = head;
    while(tail) {
        tail = tail->next;
        n++;
    }
    k = k%n;// finding new value of n;
    if(k==0) {return head;}

    Node* ptr1 = head;
    Node* ptr2 = head;
    while(k--){
        ptr2 = ptr2->next;
    }

    while(ptr2->next) {
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
    }

    Node* nextptr = ptr1->next;// this will be our new head.
    ptr1->next = NULL;
    ptr2->next = head;

    return nextptr;
}

int main() {
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.display();

    ll.head = rotateByK(ll.head, 3);
    ll.display();
    
    return 0;
}