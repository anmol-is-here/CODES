#include<iostream>
using namespace std;

int main() {
    // Wild pointer...
    // int *ptr;
    // cout<<ptr<<" "<<*ptr;


    //NULL pointer...
    // int *ptr = NULL;
    // int *p1 = 0;
    // int *p2 = '\0';
    // cout<<ptr<<" "<<p1<<" "<<p2<<" \n";


    //Dangling pointer...
    // int *ptr = NULL;
    // {
    //     int x = 10;
    //     ptr = &x;
    //     cout<<*ptr<<"\n";
    // }
    // cout<<*ptr;


    //void pointer...
    float f = 10.2;
    int x = 10;
    void *ptr = &f;
    ptr = &x;
    // ptr = &f;

    cout<<*(int*)ptr;
    return 0;
}