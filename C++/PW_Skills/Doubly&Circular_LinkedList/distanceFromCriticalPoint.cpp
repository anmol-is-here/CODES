/**
 * Question -> Given a linked list tail, return an array of length 2 containing [minDistance,maxDistance]
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

bool isCriticalPoint(Node* &currNode) {
    if(currNode->prev->val < currNode->val and currNode->next->val < currNode->val){
        return true;
    }
    if(currNode->prev->val > currNode->val and currNode->next->val > currNode->val){
        return true;
    }
    return false;
}

vector<int> distanceBetweenCriticalPoints(Node* tail){
    vector<int> ans(2, INT16_MAX);
    int firstCP {-1}, lastCP {-1};

    Node* currNode = tail->prev;
    if (currNode == NULL) {
        ans[0]=ans[1]=-1;
        return ans;
    }
    int currpos {0}; // givec the position of current critical point.
    while(currNode->prev!=NULL) {
        if(isCriticalPoint(currNode)) {
            if(firstCP == -1){
                firstCP=lastCP=currpos;
            }
            else{
                ans[0] = min(ans[0], currpos-lastCP);
                lastCP = currpos;
                ans[1] = lastCP - firstCP;
            }
        }
        currpos++;
        currNode = currNode->prev;
    }
    if(ans[0] == INT16_MAX) {
        ans[0]=ans[1]=-1;
    }
    return ans;
}

int main() {
    Double_LinkedList dll;
    dll.insertAtTail(1);
    dll.insertAtTail(5);
    dll.insertAtTail(4);
    dll.insertAtTail(2);
    dll.insertAtTail(6);
    dll.insertAtTail(3);
    dll.display();
    vector<int> ans = distanceBetweenCriticalPoints(dll.tail);
    cout<<ans[0]<<" "<<ans[1]; 
    
    return 0;
}