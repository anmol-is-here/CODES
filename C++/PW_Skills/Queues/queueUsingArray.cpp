#include <iostream>
#include <vector>
// #include <string>
using namespace std;

class Queue{
    int front;
    int back;
    vector<int> v;
    int cs; // current size of circular queue.
    int ts; // total size of circular queue.
public:
    Queue(int n){
        v.resize(n);
        front = 0;
        back = n-1;
        cs = 0;
        ts = n;
    }

    void enqueue(int data){
        if(isFull()) return;
        back = (back+1)%ts;
        v[back] = data;
        cs++;
    }

    void dequeue(){
        if(isEmpty()) return;
        front = (front+1)%ts;
        cs--;
    }

    int getFront(){
        if(front == -1){
            return -1;
        }
        else {
            return v[front];
        }
    }

    bool isEmpty(){
        return cs == 0;
    }

    bool isFull(){
        return cs == ts;
    }
};

int main() {
    Queue qu(3);
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.dequeue();
    qu.enqueue(40);
    qu.dequeue();
    qu.dequeue();
    qu.dequeue();
    qu.enqueue(400);
    qu.enqueue(500);

    while(!qu.isEmpty()){
        cout<<qu.getFront()<<" ";
        qu.dequeue();
    } cout<<endl;

    return 0;
}