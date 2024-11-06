/**
 * Question -> 2-pointer pattern - Given two linked list, print if they are equal or not
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

bool checkEqual_LL(Node* head1, Node* head2) {
    Node* ptr1 = head1;
    Node* ptr2 = head2;

    while (ptr1!=NULL and ptr2!=NULL) {
        if (ptr1->val!=ptr2->val) {
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    // either ptr1=NULL or ptr2=NULL or both equal to NULL.
    return (ptr1==NULL and ptr2==NULL);
}

int main() {
    LinkedList ll1;
    LinkedList ll2;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(4);
    ll1.insertAtTail(3);

    ll2.insertAtTail(1);
    ll2.insertAtTail(2);
    ll2.insertAtTail(3);
    ll2.insertAtTail(4);

    ll1.display();
    ll2.display();

    cout<<checkEqual_LL(ll1.head, ll2.head);
    
    return 0;
}