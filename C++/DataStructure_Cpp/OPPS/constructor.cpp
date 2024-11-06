#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Rectangle {
public:
    int l;
    int b;
    Rectangle() {       // Default constructor - no argument passed.
        l = 0;
        b = 0;
    }

    Rectangle(int x, int y) {       // parameterised constructor - args passed.
        l = x;
        b = y;
    }

    Rectangle(Rectangle& r) {       // copy constructor - initialize an object by another existing object.
        l = r.l;
        b = r.b;
    }

    ~Rectangle() {
        cout<<"Destructor is called"<<endl;
    }
};

int main() {
    Rectangle* r1 = new Rectangle();
    cout<<r1->l<<" "<<r1->b<<endl; 
    delete r1;
    
    Rectangle r2(3, 4);
    cout<<r2.l<<" "<<r2.b<<endl;

    Rectangle r3 {r2};
    cout<<r3.l<<" "<<r3.b<<endl;
    return 0;
}