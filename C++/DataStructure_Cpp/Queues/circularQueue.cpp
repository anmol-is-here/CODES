#include <iostream>
#include <vector>
// #include <string>
using namespace std;

class Queue{
    int front;
    int back;
    vector<int> v;
public:
    Queue(){
        front = -1;
        back = -1;
    }

    void enqueue(int data){
        v.push_back(data);
        back++;
        if(back == 0){ // this condition is required when element inserted in a queue first time.
            front = 0;
        }
    }

    void dequeue(){
        if(front == back){
            front = -1;
            back = -1;
            v.clear();
        }
        else{
           front++; 
        }
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
        return front == -1;
    }
};

int main() {
    Queue qu;
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