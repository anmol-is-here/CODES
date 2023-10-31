#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int leastInterval(vector<char> task, int n){
    
    priority_queue<int> pq;
    unordered_map<char, int> mp;
    int totalTime {0};

    for(auto t : task){
        mp[t]++;
    }

    for(auto freq : mp){
        pq.push(freq.second);
    }
    
    while(!pq.empty()){
        vector<int> temp;

        for(int i = 0; i <= n; i++){
            if(!pq.empty()){
                int freq = pq.top();
                pq.pop();

                if(freq > 1){
                    temp.push_back(freq-1);
                }
            }
            totalTime++;

            if(pq.empty() and temp.empty()){
                return totalTime;
            }
        }
        for(auto x : temp){
            pq.push(x);
        }
    }

    return totalTime;



}

int main() {
    vector<char> tasks {'A','A','A','A','B','B','B'};
    int cooltime = 2;

    cout<<leastInterval(tasks, cooltime);
    
    return 0;
}