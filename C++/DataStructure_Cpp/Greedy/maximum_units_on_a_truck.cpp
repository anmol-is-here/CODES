// https://leetcode.com/problems/maximum-units-on-a-truck/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[1] > b[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxType, int truckSize) {
        sort(boxType.begin(), boxType.end(), cmp);
        int ans = 0;
        for(int i = 0; i < boxType.size(); i++){
            if(boxType[i][0] <= truckSize){
                ans += boxType[i][0] * boxType[i][1];
                truckSize -= boxType[i][0];
            }
            else{
                ans += truckSize * boxType[i][1];
                truckSize = 0;
            }
            if(truckSize == 0) break;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}