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

void deleteAlternateNodes(Node* &head) {
    Node* curr_node = head;
    while(curr_node!=NULL && curr_node->next!=NULL) {
        Node* temp = curr_node->next;
        curr_node->next = curr_node->next->next;
        delete temp;
        curr_node = curr_node->next;
    }
}

int main() {

    LinkedList ll;
    for(int i = 1; i <= 6; i++){
        ll.insertAtTail(i);
    }
    ll.display();
    deleteAlternateNodes(ll.head);
    ll.display();
    
    return 0;
}