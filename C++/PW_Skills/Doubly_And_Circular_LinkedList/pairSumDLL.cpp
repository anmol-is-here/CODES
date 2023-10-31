/**
 * Question -> For a given sorted doubly linked list, find if there exists a pair of distinct nodes such that the sum of their values is x.
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

vector<int> pairSum(Node* head, Node* tail, int x) {
    vector<int> ans(2, -1);
    while(tail!=head and tail->next!=head) {
        int sum = head->val + tail->val;
        if(sum == x) {
            ans[0] = head->val;
            ans[1] = tail->val;
            return ans;
        }
        if(sum>x){
            tail = tail->prev;
        }
        else {
        head = head->next; 
        }
    }
    return ans;
}

int main() {
    Double_LinkedList dll;
    dll.insertAtTail(2);
    dll.insertAtTail(5);
    dll.insertAtTail(6);
    dll.insertAtTail(8);
    // dll.insertAtTail(9);
    dll.insertAtTail(10);
    dll.display();

    vector<int> ans = pairSum(dll.head, dll.tail, 11);
    cout<<ans[0]<<" "<<ans[1];
    
    return 0;
}