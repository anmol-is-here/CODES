/**
 * Question -> Given the head of a doubly linked list, reverse it.
*/

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

    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

void reverse_dll(Node* &head, Node* &tail) {
    Node* currptr = head;
    while(currptr) {
        Node* nextptr = currptr->next;
        currptr->next = currptr->prev;
        currptr->prev = nextptr;
        currptr = nextptr;
    }
    // swaapping head and tail pointers.
    Node* newHead = tail;
    tail = head;
    head = newHead;
    return;
}

int main() {
    Double_LinkedList dll;
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(3);
    dll.insertAtTail(4);
    dll.display();
    reverse_dll(dll.head, dll.tail);
    dll.display();
    
    return 0;
}