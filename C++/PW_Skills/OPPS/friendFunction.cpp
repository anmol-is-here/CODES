#include <iostream>
#include <vector>
#include <string>
using namespace std;

class A{
    int x;
public:
    A(int y) {
        x=y;
    }
    friend void print(A &obj);
};

void print(A &obj) {
    cout<<obj.x<<endl;
}

int main() {
    A obj1(5);

    print(obj1);

    
    return 0;
}