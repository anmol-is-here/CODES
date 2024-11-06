#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int Kth_LargestElement(vector<int> v, int size, int k){
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < size; i++){
        pq.push(v[i]);
        if(pq.size() > k){
            pq.pop();
        }
    }
    return pq.top();
}

int main() {
    vector<int> v = {50,80,10,20,5};
    int size = 5;
    int k = 5;
    cout<<Kth_LargestElement(v, size, k);
    
    return 0;
}