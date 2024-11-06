#include<iostream>
using namespace std;

int main() {
    int arr[2] = {5, 8};
    int *ptr = &arr[0];

    // cout<<*ptr<<" "<<(*ptr)++<<" "<<*ptr<<"\n";
    cout<<arr[0]<<" "<<arr[1]<<" "<<*(arr+1)<<"  "<<*(++ptr);
    return 0;
}