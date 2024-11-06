#include<iostream>
// #include<vector>
using namespace std;

int main() {
    // int a = 10, b= 0;
    // cout<<&a<<" "<<&b<<endl;
    // int *ptr = &a;
    // cout<<ptr<<endl;
    // cout<<*ptr<<endl;

    // a = 54;
    // cout<<ptr<<endl;
    // cout<<*ptr<<endl;

    // int valueAtPtr = *ptr;
    // cout<<valueAtPtr<<endl;


    // code for adding two numbers using pointers.

    int x = 20, y = 30;
    int *ptrx = &x;
    int *ptry = &y;
    int result;
    int *ptr_result = &result;

    *ptr_result = *ptrx + *ptry;

    // result = x + y;

    cout<<result<<endl;
    cout<<*ptr_result<<endl;

    return 0;
}