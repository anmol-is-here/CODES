#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Complex {
public:
    int real;
    int img;

    Complex (int x=0, int y=0) {
        real = x;
        img = y;
    }

    Complex operator+ (Complex &c) {
        Complex ans;
        ans.real = real + c.real;
        ans.img = img + c.img;
        return ans;
    }

}; 

int main() {

    Complex c1(2,4);
    Complex c2(1,6);

    Complex c3 = c1 + c2;
    cout<<c3.real<<" + "<<c3.img<<"i";
    
    return 0;
}