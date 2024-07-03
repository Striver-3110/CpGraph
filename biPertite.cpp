#include <iostream>
#include <vector>

using namespace std;

// static int __star = [] {
//     ios_base::sync_with_stdio(0);
//     cin.tie(NULL), cout.tie(NULL);
//     return 0;
// }();


class Solution{
private:
    bool dfs(int u, vector<vector<int>>& adj, vector<int> &color, int c){
        color[u] = c;
        for(auto &v: adj[u]){
            if(color[v] != -1 && color[v] == c) return false;
            if(color[v] != -1 && color[v] != c) continue;
            if(color[v] == -1 && !dfs(v,adj,color,1-c))return false;
        }
        return true;
    }
    bool bfs(int u, vector<vector<int>>& adj, vector<int> &color, int c){
        color[u] = c;

        queue<int> q;
        q.push(u);

        while(!q.empty()){
            int node = q.front();q.pop();
            int clr = color[node];
            for(auto &v: adj[node]){
                if(color[v] != -1 && color[v] == clr)return false;
                if(color[v] != -1 && color[v] != clr) continue;
                if(color[v] == -1)q.push(v),color[v] = 1-clr;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> color(n,-1);
        // for(int i = 0; i < n; i++){
        //     if(color[i] == -1 && !dfs(i,adj,color,0))return false;
        // }
        // return true;
        for(int i = 0; i < n; i++){
            if(color[i] == -1 && !bfs(i,adj,color,0))return false;
        }
        return true;

    }
};
int main()
{
    vector<vector<int>> adjacencyMatrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};

    Solution solution;
    bool isBipartiteResult = solution.isBipartite(adjacencyMatrix);

    if (isBipartiteResult)
    {
        cout << "The graph is bipartite." << endl;
    }
    else
    {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}
