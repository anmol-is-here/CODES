#include <iostream>
#include <vector>
// #include <string>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int val) {
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

void insertAtTail(Node* &head, int val) {
    Node* new_node = new Node(val);
    Node* temp = head;
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    // temp has reached to the last node.
    temp->next = new_node;
}

void insertAtPosition(Node* &head, int val, int pos) {
    Node* new_node = new Node(val);

    if(pos == 0) {
        insertAtHead(head, val);
        return;
    }

    Node* temp = head;
    int curr_pos {0};
    while(curr_pos!=pos-1){
        temp = temp->next;
        curr_pos++;
    }

    // temp is pointing to a node at pos-1.

    new_node->next = temp->next;
    temp->next = new_node;
}

void updationAtPos(Node* &head, int value, int pos) {
    // if(pos == 0){
    //     head->val = value;
    //     return;
    // }

    Node* temp = head;
    int curr_pos {0};
    while(curr_pos!=pos) {
        temp = temp->next;
        curr_pos++;
    }
    temp->val = value;
}

void deletionAtHead(Node* &head){
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deletionAtTail(Node* &head) {
    Node* temp = head;
    while(temp->next->next!=NULL) {
        temp = temp->next;
    }
    // temp will point to second last node.
    Node* temp2 = temp->next;  // node to be deleted.
    temp->next = NULL;
    delete temp2;
}

void deletionAtPoa(Node* &head, int pos) {
    if(pos == 0) {
        deletionAtHead(head);
        return;
    }
    Node* temp = head;
    int curr_pos {0};
    while (curr_pos!=pos-1) {
        temp = temp->next;
        curr_pos++;
    }
    // temp will point to pos-1;
    Node* temp2 = temp->next; //node to be deleted is stored in temp2.
    temp->next = temp2->next;
    delete temp2;

}

void display(Node* head) {
    Node* temp = head;
    while(temp!=NULL) {
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"Null"<<endl;
}

int main() {
    Node* head = NULL;
    insertAtHead(head, 2);
    display(head);
    insertAtHead(head, 5);
    display(head);
    insertAtHead(head, 7);
    display(head);
    insertAtHead(head, 6);
    display(head);
    insertAtTail(head, 30);
    display(head);
    insertAtPosition(head, 20, 3);
    display(head);
    updationAtPos(head, 8, 0);
    display(head);
    deletionAtHead(head);
    display(head);
    deletionAtTail(head);
    display(head);
    deletionAtPoa(head, 2);
    display(head);

    
    return 0;
}