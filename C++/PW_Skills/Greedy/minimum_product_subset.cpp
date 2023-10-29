#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minProduct(vector<int> &arr){
    int cn = 0, cz = 0, cp = 0;
    int prod_neg = 1;
    int prod_pos = 1;
    int largestNegative = INT32_MIN;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] < 0){
            cn++;
            prod_neg *= arr[i];
            largestNegative = max(arr[i], largestNegative);
        }
        if(arr[i] == 0){
            cz++;
        }
        if(arr[i] > 0){
            cp++;
            prod_pos *= arr[i];
        }
    }

    if(!cn){
        if(cz){
            return 0;
        }
        else{
            return *(min_element(arr.begin(), arr.end()));
        }
    }
    else{
        if(cn%2 == 0){
            // even negative nums.
            return (prod_neg / largestNegative) * prod_pos;
        }
        else{
            // odd negative nums.
            return prod_neg * prod_pos;
        }
    }
}

int main() {
    vector<int> arr {-2,-3,1,4,-2,-5};
    cout<<minProduct(arr);
    
    return 0;
}