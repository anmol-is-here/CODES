#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> K_ClosestPoint(vector<pair<int, int>> pts, int size, int k){
    priority_queue<pair<int, pair<int, int>>> pq;

    for(auto &pt:pts){
        int dist = pt.first + pt.second;
        pq.push(make_pair(dist, pt));
        if(pq.size() > k){
            pq.pop();
        }
    }

    vector<pair<int, int>> ans(k);
    while(!pq.empty()){
        ans[pq.size()-1] = pq.top().second;
        pq.pop();
    }
    return ans;
}

int main() {

    vector<pair<int, int>> pts = {{5,3},{1,2},{3,4},{5,6},{7,8},{9,10}};
            
    vector<pair<int, int>> ansPts = K_ClosestPoint(pts, 6, 3);
    for(auto &pt:ansPts){
        cout<<pt.first<<" "<<pt.second<<endl;
    } 
    
    return 0;
}