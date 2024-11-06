#include<iostream>
using namespace std;

int main() {
    int x = 9;
    float y = 2.5;
    double z = 2.75;

    int *ptr = &x;
    float *ptrf = &y;
    double *ptrd = &z;

    cout<<sizeof(x)<<" \n"<<(sizeof y)<<" \n"<<sizeof(z)<<" \n";

    cout<<(ptr)<<" "<<(ptr+1)<<" \n"<<(ptrf+1)<<" "<<(ptrf+2)<<" \n"<<(ptrd+1)<<" "<<(ptrd+2)<<" "<<(ptrd+3);
    return 0;
}