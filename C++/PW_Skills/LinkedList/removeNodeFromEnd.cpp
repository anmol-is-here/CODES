/**
 * Question -> Given the head of a linked list, remove the kth node from the end of the list and return its head.
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

// the value of k must be less than or equal to the no. of nodes.
void remove_kth_NodeFromEnd(Node* &head, int k) {
    Node* ptr1 = head;
    Node* ptr2 = head;

    int count {k};
    // move ptr2 by k steps ahed.
    while(count--){
        ptr2 = ptr2->next;
    }

    if(ptr2==NULL) { // k is equal to head of linked list.
        // we have to delete head node.
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    while(ptr2->next){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    // ptr1 is pointing to the node before kth node to be deleted.
    Node* temp = ptr1->next;
    ptr1->next = ptr1->next->next;
    delete temp;

}

int main() {
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.display();
    remove_kth_NodeFromEnd(ll.head, 3);
    ll.display();
    
    
    return 0;
}