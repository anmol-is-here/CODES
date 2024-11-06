// https://leetcode.com/problems/meeting-rooms-ii

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int minMeetingRooms(vector<vector<int>> &intervals){
        vector<int> start, ending;
        for(auto el : intervals){
            start.push_back(el[0]);
            ending.push_back(el[1]);
        }
        sort(start.begin(), start.end());
        sort(ending.begin(), ending.end());
        int i = 0, j = 0;
        int ans = 0;
        int room = 0;
        while(i < start.size() and j < ending.size()){
            if(start[i] < ending[j]){
                // a meeting is starting.
                room++;
                ans = max(ans, room);
                i++;
            }
            else if(start[i] > ending[j]){
                // meeting is ending.
                room--;
                j++;
            }
            else{
                i++;
                j--;
            }
        }
        return ans;
    }

// https://leetcode.com/problems/meeting-rooms

    bool canAttendMeeting(vector<vector<int>> &intervals){
        if(intervals.size() == 0) return true;
        
        return minMeetingRooms(intervals) == 1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> inte {{0,30}, {5,10}, {15,20}};
    cout<<s.minMeetingRooms(inte);
    cout<<endl;
    cout<<s.canAttendMeeting(inte);
    
    return 0;
}