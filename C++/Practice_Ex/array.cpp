#include<iostream>
using namespace std;

int main() {
    int arr[] = {1, 12, 5, 8, 17};
    int max = arr[0];
    for (int i = 0; i < 5; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    cout<<max<<endl;
    return 0;
}