/**
 * Slow-fast pointer - Find the middle element of a given linked list
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

Node* findMiddle(Node* &head) {
    Node* slow = head;
    Node* fast = head;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    LinkedList ll;
    for (int i=1; i<=6; i++) {
        ll.insertAtTail(i);
    }
    ll.display();

    Node* Middle = findMiddle(ll.head);
    cout<<Middle->val;
    
    return 0;
}