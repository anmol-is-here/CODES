/**
 * Question -> Given the head of a doubly linked list, delete the nodes whose neighbors have the same value.
 * Traverse the list from right to left.
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

void deleteSameNeighbourNode(Node* &head, Node* tail){
    Node* currNode = tail->prev;
    while(currNode!=head){
        Node* prev = currNode->prev;
        Node* next = currNode->next;
        if(prev->val == next->val){
            // need to delete currNode.
            currNode->prev->next = currNode->next;
            currNode->next->prev = currNode->prev;
            free(currNode);
        }
        currNode = prev;
    }
}

int main() {
    Double_LinkedList dll;
    dll.insertAtTail(2);
    dll.insertAtTail(1);
    // dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(1);
    dll.display();
    deleteSameNeighbourNode(dll.head, dll.tail);
    dll.display();
    
    return 0;
}