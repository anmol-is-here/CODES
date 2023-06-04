#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Parent{
public:
    virtual void print(){
        cout<<"parent class"<<endl;
    }
    void show(){
        cout<<"parent class"<<endl;
    }
};

class Child: public Parent{
   public:
    void print(){
        cout<<"child class"<<endl;
    }
    void show(){
        cout<<"child class"<<endl;
    } 
};

int main() {
    Parent *p;
    Child c;
    
    p = &c;               // overridding of function only take place if we use virtual keyword.
    p->print();
    p->show();

    return 0;
}