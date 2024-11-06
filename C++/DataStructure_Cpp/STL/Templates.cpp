#include <iostream>
#include <vector>
// #include <string>
using namespace std;

template <typename T> 
class Node{
public:
    T val;
    Node* next;
    Node(T data){
        val = data;
        next = NULL;
    }
};

int main() {
    Node<int>* new_node = new Node<int> (3);
    Node<char>* new_node1 = new Node<char> ('a');
    cout<<new_node->val<<endl;
    cout<<new_node1->val<<endl;

    return 0;
}