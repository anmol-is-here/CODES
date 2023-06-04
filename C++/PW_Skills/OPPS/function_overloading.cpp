#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Sum {
    public:
    void add (int x, int y){
        int sum = x + y;
        cout<<sum<<endl;
    }

    void add(int x, int y, int z) {
        int sum = x + y + z;
        cout<<sum<<endl;
    }

    void add(float x, float y) {
        float sum = x + y;
        cout<<sum<<endl;
    }
};

int main() {
    Sum s1;
    s1.add(2,3);
    s1.add(2,3,5);
    s1.add(float(2.5),float(3.3));
    return 0;
}