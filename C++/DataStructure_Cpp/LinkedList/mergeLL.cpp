/**
 * Question.1 -> Given 2 sorted linked lists, merge them into 1 singly linked list such that the resulting list is also sorted.
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

Node* merge_LL(Node* &head1, Node* &head2) {
    Node* dummyHead = new Node(-1);

    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* ptr3 = dummyHead;

    while(ptr1 and ptr2){
        if (ptr1->val < ptr2->val) {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }

    if(ptr1) {
        ptr3->next = ptr1;
    }
    else {
        ptr3->next = ptr2;
    }
    return dummyHead->next;
}

/**
 * Question.2 -> Given an array of k linked list, each linked list is sorted in ascending order, merge all the linked list in one sorted linked list and return it.
*/

Node* mergeK_LL(vector<Node*> &list) {
    if (list.size() == 0) {
        return NULL;
    }

    while(list.size()>1) {
        Node* mergrdHead = merge_LL(list[0], list[1]);
        list.push_back(mergrdHead);
        list.erase(list.begin());
        list.erase(list.begin());
    }
    return list[0];
}

int main() {
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.insertAtTail(7);

    LinkedList ll2;
    ll2.insertAtTail(2);
    ll2.insertAtTail(8);

    LinkedList ll3;
    ll3.insertAtTail(3);
    ll3.insertAtTail(6);
    ll3.insertAtTail(9);

    ll1.display();
    ll2.display();
    ll3.display();

    // LinkedList ll3;
    // ll3.head = merge_LL(ll1.head, ll2.head);
    // ll3.display();

    vector<Node*> list;
    list.push_back(ll1.head);
    list.push_back(ll2.head);
    list.push_back(ll3.head);

    LinkedList merged;
    merged.head = mergeK_LL(list);
    merged.display();

    return 0;
}