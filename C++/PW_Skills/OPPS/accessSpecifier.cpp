#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Parent {
public :
    int x;

protected :
    int y;

private :
    int z;
};

class Child1: public Parent {
    // x will be public
    // y will be private
    // z will not be accessiable
};


class Child2: protected Parent {
    // x will be protected
    // y will be protected
    // z will not be accessiable
};


class Child3: private Parent {
    // x will be private
    // y will be private
    // z will not be accessiable
};

int main() {

    Parent  p;
    p.x;
    
    return 0;
}