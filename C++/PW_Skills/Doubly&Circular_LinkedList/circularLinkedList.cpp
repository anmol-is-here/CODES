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

class CircularLinkedList{
public:
    Node* head;
    CircularLinkedList(){
        head = NULL;
    }

        // Insertion and deletion at kth position is same as that in case of singli linked list.
        // Updation is also sme as of singli linked list.

    void insertAtHead(int val){
        Node* new_node = new Node(val);
        if(head==NULL) {
            head = new_node;
            new_node->next = head;
            return;
        }
        Node* temp = head;
        while(temp->next!=head) {
            temp = temp->next;
        }
        new_node->next = head;
        temp->next = new_node;
        head = new_node;
        return;
    }

    void insertAtTail(int val){
        Node* new_node = new Node(val);
        if(head == NULL){
            head = new_node;
            new_node->next = head;
            return;
        }
        Node* tail = head;
        while(tail->next!=head){
            tail = tail->next;
        }

        tail->next = new_node;
        new_node->next = head;
        return;
    }

    void deletionAtHead(){
        if (head==NULL) {return;}
        Node* temp = head;
        Node* tail = head;
        while(tail->next!=head){
            tail = tail->next;
        }

        head = head->next;
        tail->next = head;
        free(temp);
    }

    void deletionAtTail(){
        if (head == NULL) {return;}
        // Node* temp = head;
        Node* tail = head;
        while(tail->next->next!=head){
            tail = tail->next;
        }

        Node* temp = tail->next;
        tail->next = head;
        free(temp);
    }

    void display(){
        Node* temp = head;
        do
        {
            cout<<temp->val<<" ";
            temp = temp->next;
        } while (temp!=head);
        cout<<endl;
        
        return;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtHead(1);
    cll.insertAtHead(2);
    cll.insertAtHead(3);
    cll.insertAtHead(4);
    cll.display();
    cll.insertAtTail(5);
    cll.display();
    cll.deletionAtHead();
    cll.display();
    cll.deletionAtTail();
    cll.display();
    
    return 0;
}