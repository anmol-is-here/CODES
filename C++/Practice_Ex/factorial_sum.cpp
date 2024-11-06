#include<iostream>
using namespace std;

int fact (int num) {
    if (num == 1 || num == 0) {
        return 1;
    }
    else {
        return (fact(num-1) * num);
    }
}

int main() {
    float n = 4, x = 2;
    float sum = 0;
    for (int i = 1; i <= 2; i++) {
        // sum += fact(i);

        // sum += x/fact(i);

        // if (i%2 != 0) {
        //     sum += x/fact(i);
        // }

        // if (i%2 == 0) {
        //     sum += x/fact(i);
        // }

        // sum += i*(i+1)*(i+2);
    }
    cout<<sum<<endl;
    return 0;
}