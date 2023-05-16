#include <iostream>
#include <vector>
#include <string>
using namespace std;

class fruit {
public:
    string name;
    string color;
};

int main() {
    fruit apple;   // Object of fruit class
    apple.name = "Apple";
    apple.color = "Red";
    cout<<apple.name<<"--"<<apple.color<<endl;

    fruit *mango = new fruit();
    mango->color = "Yellow";
    mango->name = "Mango";
    cout<<mango->name<<"--"<<mango->color<<endl;
    return 0;
}