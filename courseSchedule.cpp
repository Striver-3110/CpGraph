#include<bits/stdc++.h>
using namespace std;
static int __star = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    return 0;
}();
#define pb(a) push_back(a)




class Solution {
private:
    bool isCycleDfs(int u,unordered_map<int,vector<int>> &adj, vector<bool> &visited, vector<bool> &inRecursion){
        visited[u] = true;
        inRecursion[u] = true;
        for(auto &v: adj[u]){
            if(visited[v] && inRecursion[v]) return true;
            if(!visited[v] && isCycleDfs(v,adj,visited,inRecursion))return true;
        }
        inRecursion[u] = false;
        return false; 
    }
    bool isCycleBfs(int n, vector<vector<int>> &adj){
        vector<int> inDegree(n,0);
        for(int i = 0; i < n; i++){
            for(auto &v: adj[i]){
                inDegree[v]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0)q.push(i);
        }
        int node = 0;
        while(!q.empty()){
            int u = q.front();q.pop();
            node++;
            for(auto &v : adj[u]){
                if(inDegree[v] == 0) continue;
                inDegree[v]--;
                if(inDegree[v] == 0) q.push(v);
                
            }
        }
        if(node != n){
            return true;
        }
        return false;
    }

public:
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < a.size(); i++){
            adj[a[i][1]].push_back(a[i][0]);
        }

        // USING DFS 
        vector<bool> visited(n,false);
        // vector<bool> inRecursion(n,false);
        // for(int i = 0; i < n; i++){
        //     if(!visited[i] && isCycleDfs(i,adj,visited,inRecursion)) return false;
        // }
        // USING KAHN'S ALGORITHM
        if(isCycleBfs(n,adj))return false;
        // }
        return true;
    }
};
int main()
{
    Solution solution;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};
    bool result = solution.canFinish(numCourses, prerequisites);

    if (result)
    {
        cout << "It is possible to finish all courses." << endl;
    }
    else
    {
        cout << "It is not possible to finish all courses due to cyclic dependencies." << endl;
    }

    return 0;
}
