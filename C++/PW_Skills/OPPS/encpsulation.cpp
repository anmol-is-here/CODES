#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ABC {
    int x;

    public:
    
    void set(int n) {
        x = n;
    }
    int get() {
        return x;
    }
};

int main() {
    ABC obj1;
    obj1.set(7);
    cout<<obj1.get()<<endl;    
    return 0;
}