// Using BFS.

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
#include <limits.h>
using namespace std;

vector<list<int> > graph;
unordered_set<int> visited;
int v; // number of vertices.
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
    return;
}

void bfs(int src, vector<int> &dist){
    queue<int> q;
    visited.clear();
    dist.resize(v, INT_MAX);
    dist[src] = 0;
    visited.insert(src);
    q.push(src);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        visited.insert(curr);
        for(auto neighbour : graph[curr]){
            if(not visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour] = dist[curr] + 1;
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    cin>>v;
    graph.resize(v, list<int> ());
    int e;
    cin>>e;
    visited.clear();
    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s, d);
    }

    int src;
    cin>>src;
    vector<int> dist;
    bfs(src, dist);

    for(auto ele : dist) cout<<ele<<" ";
    
    
    return 0;
}