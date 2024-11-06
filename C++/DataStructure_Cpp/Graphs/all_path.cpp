// Using DFS.

#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

vector<list<int> > graph;
unordered_set<int> visited;
vector<vector<int> > result;
int v; // number of vertices.
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
    return;
}

void dfs(int curr, int end, vector<int> &path){
    if(curr == end){
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr);
    path.push_back(curr);
    for(int neighbour : graph[curr]){
        if(not visited.count(neighbour)){
            dfs(neighbour, end, path);
        }
    }
    path.pop_back();
    visited.erase(curr);
    return ;
}

void all_path(int src, int dest){
    vector<int> path;
    dfs(src, dest, path);
    return;
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

    int src, dest;
    cin>>src>>dest;

    all_path(src, dest);
    for(auto path : result){
        for(int ele : path){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}