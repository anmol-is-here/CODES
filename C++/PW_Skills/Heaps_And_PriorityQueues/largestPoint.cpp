#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int largestele(vector<int> v, int size, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto i:v){
        pq.push(i);
    }

    while(k--){
        int firstEle = pq.top();
        pq.pop();
        int secondEle = pq.top();
        pq.pop();
        int product = firstEle * secondEle;
        pq.push(product);
    }

    while(pq.size()>1){
        pq.pop();
    }

    return pq.top();
}

int main() {

    vector<int> v = {2,4,3,1,5};
    int size {5};
    int k {3};
    cout<<largestele(v, size, k);
    
    return 0;
}