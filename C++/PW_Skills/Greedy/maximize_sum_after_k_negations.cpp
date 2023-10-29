

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) { // O(klog(n) + n).
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());  // O(n).

        int sum = 0;
        for(int x : nums){
            sum += x;
        }

        while(k--){
            int curr = pq.top();
            if(curr == 0){
                break;
            }
            pq.pop(); // remove smallest element.
            sum -= curr;
            pq.push(-1*curr);  // add negated element.
            sum += (-curr);
        }
        return sum;
    }
};

int main() {
    
    return 0;
}