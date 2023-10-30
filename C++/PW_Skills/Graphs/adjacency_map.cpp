#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<unordered_set<int> > graph;
int v;     // no. of vertices.

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].insert(dest);
    if(bi_dir) {
        graph[dest].insert(src);
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

int main(int argc, char const *argv[]) {

    cin>>v;
    graph.resize(v, unordered_set<int> ());
    int e;
    cin>>e;
    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s, d);
    }
    display();
    
    return 0;
}