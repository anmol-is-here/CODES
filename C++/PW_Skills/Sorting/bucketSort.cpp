#include<iostream>
#include<vector>
using namespace std;

void bucketSort(vector <float> &v){
    
}

int main() {
    vector <float> v{0.32,0.78,0.45,0.62,0.12,0.55};

    bucketSort(v);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}