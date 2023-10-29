// https://leetcode.com/problems/boats-to-save-people/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0;
        int j = people.size()-1;
        int  bt = 0;

        while(i <= j){
            if(people[i] + people[j] <= limit){
                i++;
                j--;
                bt++;
            }
            else{
                j--;
                bt++;
            }
        }
        return bt;
    }
};

int main() {
    
    return 0;
}