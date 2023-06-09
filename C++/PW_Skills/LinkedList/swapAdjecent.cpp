/**
 * Question -> For a given linked list swap every adjacent node and return its head.
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

Node* swapAdjecent(Node* &head){
    // base case.
    if (head == NULL or head->next == NULL) {
        return head;
    }

    // recursive case.
    Node* secondNode = head->next;
    head->next = swapAdjecent(secondNode->next);
    secondNode->next = head; // reversing the link between second and first node.
    return secondNode;
}

int main() {
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    // ll.insertAtTail(6);
    ll.display();

    ll.head = swapAdjecent(ll.head);
    ll.display();
    
    return 0;
}