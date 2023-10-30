#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

vector<list<int> > graph;
int v;     // no. of vertices.

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) {
        graph[dest].push_back(src);
    }
}

void display(){
    for(int i = 0; i < graph.size(); i++){
        cout<<i<<" -> ";
        for(auto el : graph[i]){
            cout<<el<<", ";
        }
        cout<<endl;
    }
}

void dfs(int node, unordered_set<int> &visited){
    visited.insert(node);
    for(auto neighbour : graph[node]){
        if(not visited.count(neighbour)){
            dfs(neighbour, visited);
        }
    }
}

int connectedComponects() {
    int result = 0;
    unordered_set<int> visited;
    for(int  i = 0; i < v; i++){
        // go to every vertix
        // if from every vertix we are able to initialize a dfs, we got a new connectead component.
        if(visited.count(i) == 0){
            result++;
            dfs(i, visited);
        }
    }
    return result;
}

int main(int argc, char const *argv[]) {

    cin>>v;
    graph.resize(v, list<int> ());
    int e;
    cin>>e;
    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s, d, false);
    }
    cout<<connectedComponects()<<endl;
    
    return 0;
}