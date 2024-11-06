#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Parent1 {
public:
    Parent1(){
        cout<<"parent1 class"<<endl;
    }
};

class Parent2 {
public:
    Parent2(){
        cout<<"parent2 class"<<endl;
    }
};

class Child: public Parent1, public Parent2 {
public:
    Child(){
        cout<<"child class"<<endl;
    }
};

class GrandChild: public Child {
public:
    GrandChild(){
        cout<<"grandchild class";
    }
};

int main() {
    Child c;

    return 0;
}