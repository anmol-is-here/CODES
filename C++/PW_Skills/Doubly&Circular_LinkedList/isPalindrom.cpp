/**
 * Question ->  Given the head of a doubly linked list, find its palindrome or not.
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

bool isPalindrom(Node* head, Node* tail) {
    while (head!=tail and tail!=head->prev){
        if(head->val != tail->val) {
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    Double_LinkedList dll;
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(3);
    dll.insertAtTail(4);
    dll.insertAtTail(2);
    dll.insertAtTail(1);
    dll.display();
    cout<<isPalindrom(dll.head, dll.tail);
    
    return 0;
}