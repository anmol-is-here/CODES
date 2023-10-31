// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

/**
 * time complexity -> O((n+m)log(n+m))
 * 
 * it can be optimized by using binary search method to {O(log(m+n))}
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void resize(priority_queue<int, vector<int>, greater<int>> &max, priority_queue<int> &min){
    if(min.size() - 1 > max.size()){
        max.push(min.top());
        min.pop();
            cout<<"-";
    }
    
    else if(max.size() > min.size()){
        min.push(max.top());
        max.pop();
    cout<<"*";
    }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    priority_queue<int> min;
    priority_queue<int, vector<int>, greater<int>> max;

    int i = 0; int j = 0;
    while(nums2.size()){
        nums1.push_back(nums2.back());
        nums2.pop_back();
    }
    for(int i = 0; i < nums1.size(); i++){
        cout<<nums1[i]<<" ";
    }cout<<"#";
    while(i < nums1.size()){
        if(min.size() == 0){
            min.push(nums1[i]);
        }
        else if(nums1[i] > min.top()){
            max.push(nums1[i]);
        }
        else{
           min.push(nums1[i]); 
        }
        i++;
        resize(max, min);
    }
    cout<<min.size()<<max.size()<<endl;
    cout<<min.top()<<" "<<max.top()<<endl;
    if(min.size() > max.size()) return min.top() * 1.0;
    else return (min.top()*1.0 + max.top()*1.0)/2.0;
}

int main() {

    vector<int> num1 {4,5,6,8,9};
    vector<int> num2 {};
    cout<<findMedianSortedArrays(num1, num2)<<endl;
    
    return 0;
}