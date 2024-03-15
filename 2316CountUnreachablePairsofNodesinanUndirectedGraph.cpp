#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     void dfs(int u, vector<bool>& visited,vector<int> adj[],long long& cnt){
//         visited[u] = true;
//         for(int v : adj[u]){
//             if(!visited[v]){
//                 dfs(v,visited,adj,cnt);
//                 cnt++;
//             }
//         }

//     }
//     long long countPairs(int n, vector<vector<int>>& edges) {
//         if( n == 1){
//             return 0;
//         }
//         long long k = (long long) n;
//         if(edges.size() == 0){
//             return k*(k-1)/2;
//         }

//         // creating adjacency list

//         vector<int> adj[n];
//         int N = edges.size();
//         for(int i = 0; i < N; i++){
//             adj[edges[i][0]].push_back(edges[i][1]);
//             adj[edges[i][1]].push_back(edges[i][0]);
//         }

//         // visited array
//         vector<bool>visited(n,false);
//         // ans to store number of nodes in all the components
//         vector<long long> ans;

//         // number of nodes in a single graph

//         // actual dfs call
//         for(int i = 0; i < n; i++){
//             long long cnt = 1;
//             if(!visited[i]){
//                 dfs(i,visited,adj,cnt);
//                 cout<<cnt<<endl;
//                 ans.push_back(cnt);
//             }
//         }
//         n = ans.size();
//         long long sum = 0;
//         for(int i = 0; i < n-1; i++){
//             for(int j = i+1; j < n; j++){
//                 sum += ans[i] * ans[j];
//             }
//         }
//         return sum;
//     }
// };

class Solution
{
public:
    int find(int x, vector<int> &parent)
    {
        if (x == parent[x])
        {
            return x;
        }
        return parent[x] = find(parent[x], parent);
    }

    void _union(int x, int y, vector<int> &parent, vector<int> &rank, vector<int> &groupLength)
    {
        int px = find(x, parent);
        int py = find(y, parent);
        if (py == px)
        {
            return;
        }
        if (rank[px] > rank[py])
        {
            parent[py] = px;
            groupLength[px] += groupLength[py];
            groupLength[py] = 0;
        }
        else if (rank[px] < rank[py])
        {
            parent[px] = py;
            groupLength[py] += groupLength[px];
            groupLength[px] = 0;
        }
        else
        {
            parent[px] = py;
            rank[py]++;
            groupLength[py] += groupLength[px];
            groupLength[px] = 0;
        }
    }
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
        {
            return 0;
        }
        long long k = (long long)n;
        if (edges.size() == 0)
        {
            return k * (k - 1) / 2;
        }
        vector<int> rank(n, 0);
        vector<int> parent;
        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
        }
        int N = edges.size();
        vector<int> groupLength(n, 1);
        for (int i = 0; i < N; i++)
        {
            if (find(edges[i][0], parent) != find(edges[i][1], parent))
            {
                _union(edges[i][0], edges[i][1], parent, rank, groupLength);
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            // groupLength[py] += groupLength[px];
            cout << groupLength[i] << " ";
            for (int j = i + 1; j < n; j++)
            {
                if (groupLength[i] != 0 && groupLength[j] != 0)
                {
                    sum += groupLength[i] * groupLength[j];
                }
            }
        }
        return sum;
    }
};

int main()
{
    Solution solution;

    int n = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};

    long long result = solution.countPairs(n, edges);

    cout << "Number of pairs: " << result << endl;

    return 0;
}