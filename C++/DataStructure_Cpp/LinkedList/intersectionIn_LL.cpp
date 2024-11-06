/**
 * Question -> Given the heads of 2 linked list, return the node at which both linked list intersect. If they don't, return null.
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

int getLength(Node* head){
    Node* temp = head;
    int length {0};
    while(temp!=NULL){
        temp = temp->next;
        length++;
    }
    return length;
}

Node* moveHeadBy_k(Node* head, int k){
    Node* temp = head;
    while(k--){
        temp = temp->next;
    }
    return temp;
}

Node* getIntersection(Node* head1, Node* head2) {
    // step1=> calculate length of both LL.
    int l1 = getLength(head1);
    int l2 = getLength(head2);

    // step2=> find the difference k between the linked list and move the longer linkedList ptr by k steps.
    Node* ptr1, *ptr2;
    if(l1>l2) { // LL1 is longer.
        int k = l1-l2;
        ptr1 = moveHeadBy_k(head1, k);
        ptr2 = head2;
    }
    else { // LL2 is longer.
        int k = l2-l1;
        ptr1 = head1;
        ptr2 = moveHeadBy_k(head2, k);
    }

    while(ptr1){
        if (ptr1 == ptr2) {
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return NULL;
}

int main() {
    LinkedList ll1;
    ll1.insertAtTail(1); 
    ll1.insertAtTail(2); 
    ll1.insertAtTail(3); 
    ll1.insertAtTail(4); 
    ll1.insertAtTail(5); 
    ll1.display();

    LinkedList ll2;
    ll2.insertAtTail(6);
    ll2.insertAtTail(7);
    ll2.head->next->next = ll1.head->next->next->next;
    ll2.display();

    Node* intersection = getIntersection(ll1.head, ll2.head);
    if(intersection){
        cout<<intersection->val;
    }
    else {
        cout<<"-1";
    }

    return 0;
}