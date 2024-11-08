/**
 * Question -> Given head of a linked list, determine if the linked list is a palindrome.
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

bool isPalindrome(Node* head) {
    // 1. Find the middle element.
    Node* slow = head;
    Node* fast = head;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow will pointing to the middle node.
    // 2. break the LL in the middle.
    Node* curr = slow->next;
    Node* prev = slow;
    slow->next = NULL;

    // 3. reverse the second half of LL.
    while(curr) {
        Node* next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }

    // 4. check if the two linked list are equal.
    Node* head1 = head;
    Node* head2 = prev;

    while(head2){
        if (head1->val!=head2->val) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}

int main() {
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(3);
    ll.insertAtTail(2);
    ll.insertAtTail(1);
    ll.display();

    cout<<isPalindrome(ll.head)<<endl;
    
    return 0;
}