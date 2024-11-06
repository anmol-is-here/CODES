// Using DFS.

#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
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

bool dfs(int curr, int end){
    if(curr == end) return true;
    visited.insert(curr);
    for(int neighbour : graph[curr]){
        if(not visited.count(neighbour)){
            bool result = dfs(neighbour, end);
            if(result) return true;
        }
    }
    return false;
}

bool any_path(int src, int dest){
    return dfs(src, dest);
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
        add_edge(s, d, false);
    }

    int src, dest;
    cin>>src>>dest;
    cout<<any_path(src, dest);
    
    return 0;
}