#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;

    node(int val) {
        data=val;
        next=NULL;
    }
};

void insertAtTail(node* &head, int val){

    node* n = new node(val);

    if(head == NULL){
        head = n;
        return;
    }

    node* temp=head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;

    delete todelete;
    // free(todelete);
}

void deletion(node* &head, int val){

    if (head == NULL){
        return;
    }
    if(head->next == NULL){
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    while(temp->next->data != val){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    free(todelete);

    // delete todelete;
}

void display(node* head) {
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

node* reverse(node* &head){         // Reverse a linked list using itrative method.

    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr != NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;

    }

    return prevptr;
}

node* reverseRecursive(node* &head) {          // Reverse a linked list using recursive method.


    if(head == NULL || head->next == NULL){
        return head;
    }

    node* newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

node* reverseKNode(node* &head, int k){         // Reverse K nodes in a linked list

    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    
    int count = 0;
    while(currptr!=NULL && count<k){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if(nextptr != NULL){
        head->next = reverseKNode(nextptr, k);
    }

    return prevptr;
}

bool search(node* head, int key){       // Searching in linked list if an element is present in a linked list or not.
    node* temp = head;
    while(temp != NULL){
        if(temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void makeCycle(node* &head, int pos){    // Floyd's Algorithm (to make a cycle in linked list)
    node* temp = head;
    node* startNode;

    int count = 1;
    while(temp->next != NULL){

        if(count == pos){
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }

    temp->next = startNode;
}

bool detectCycle(node* &head){      // Floyd's Algorithm (to detect a cycle in linked list)
    node* slow = head;
    node* fast = head;

    while(fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow){
            return true;
        }
    }
    return false;

}

void removeCycle(node* &head){      // Floyd's Algorithm (to remove a cycle present in linked list)

    node* slow = head;
    node* fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    }while (slow != fast);

    fast = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
}

int length(node* head){       // find length of a linked list.
    int l=0;
    node*temp=head;
    while(temp!=NULL){
        temp=temp->next;
        l++;
    }
    return l;
}

node* kAppand(node* &head, int k){     // Appendd last k nodes of linked list.

    node* newHead;
    node* newTali;
    node* tail=head;

    int l = length(head);
    k=k%l;
    int count=1;
    while(tail->next!=NULL){
        if(count==l-k){
            newTali=tail;
        }
        if(count==l-k+1){
            newHead=tail;
        }
        tail = tail->next;
        count++;
    }

    newTali->next=NULL;
    tail->next=head;

    return newHead;
}

int intersection(node* &head1, node* &head2){      // Find intersection point of two linked list.
    int l1=length(head1);
    int l2=length(head2);

    int d=0;
    node* ptr1;
    node* ptr2;
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;

    }
    else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }

    while(d){
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    return -1;

}

void intersect(node* &head1, node* &head2, int pos){     //To intersect two linked list at a given position.

    node* temp1=head1;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    node* temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }

    temp2->next=temp1;
}

node* merge(node* &head1, node* &head2){     //Merge two sorted linked list using iterative approach.

    node* p1=head1;
    node* p2=head2;
    node* dummyNode=new node(-1);
    node* p3=dummyNode;

    while(p1!=NULL && p2!=NULL){
        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }

    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }

    while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }

    return dummyNode->next;

}

node* mergeRecursive(node* &head1, node*&head2){      //Merge two sorted linked list using Recursive approach.

    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    node* result;
    if(head1->data<head2->data){
        result=head1;
        result->next=mergeRecursive(head1->next,head2);
    }
    else{
        result=head2;
        result->next=mergeRecursive(head1,head2->next);
    }

    return result;
}

void evenAfterOdd(node* &head){         // Printing even numbers after odd numbers from given linked list element.
    node* odd=head;
    node* even=head->next;
    node* evenStart=even;
    while(odd->next!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;

    }

    odd->next=evenStart;
    if(odd->next==NULL){
        even->next=NULL;
    }
}


int main() {
    
    node* head=NULL;
    // node* head2=NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 21);
    insertAtTail(head, 34);
    insertAtTail(head, 43);
    insertAtTail(head, 51);
    insertAtTail(head, 62);
    insertAtTail(head, 73);
    // insertAtTail(head2, 10);
    display(head);
    // cout<<search(head, 3)<<endl;
    // deletion(head,4);
    // deleteAtHead(head);
    // node* newhead = reverseRecursive(head);
    // display(newhead);

    // int k = 2;
    // node* newhead = reverseKNode(head, k);


    // display(newhead);

    // makeCycle(head, 3); 
    // cout<<detectCycle(head)<<endl;
    // removeCycle(head);
    // cout<<detectCycle(head)<<endl;
    // display(head);

    // intersect(head1,head2,5);
    // display(head1);
    // display(head2);
    // cout<<intersection(head1, head2)<<endl;

    // node* newhead=mergeRecursive(head1, head2);
    // display(newhead);

    evenAfterOdd(head);
    display(head);

    return 0;
}