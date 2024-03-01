#include<iostream>
using namespace std;
#include<map>
#include<list>
#define nl "\n"
#define pb(a) push_back(a)

template<typename T>
void put(T&& args){
    cout<<args<<" ";
}

class Graph{
    public:
        map <int , bool> visited;
        map <int , list<int>> adj;

        void dfs(int v);
        void addedge(int a , int b);
};

void Graph:: addedge(int a, int b){
    adj[a].pb(b);
}

void Graph:: dfs(int v){
    visited[v] = true;
    put(v);

    for(auto it = adj[v].begin(); it != adj[v].end(); it++){
        if(!visited[*it]) dfs(*it);
    }
}

int main(){
    Graph g;
    // g.addedge(1,5);
    // g.addedge(1,2);
    // g.addedge(2,1);
    // g.addedge(2,3);
    // g.addedge(5,1);
    // g.addedge(5,3);
    // g.addedge(5,4);
    // g.addedge(3,2);
    // g.addedge(3,5);
    // g.addedge(4,5);
      g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);

    g.dfs(2);

}
