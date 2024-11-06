/**
 * Print Linked List in reverse order.
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

void reversePrint(Node* &head) {
    if(head == NULL){
        return;
    }

    reversePrint(head->next);
    cout<<head->val<<" ";
}

int main() {
    LinkedList ll;
    for (int i = 1; i<=5; i++){
        ll.insertAtTail(i);
    }
    ll.display();
    reversePrint(ll.head);
    
    return 0;
}