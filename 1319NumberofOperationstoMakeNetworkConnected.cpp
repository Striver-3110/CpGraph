//? approach 1**************************************************************************************************************************
//! using dfs

// static int _star = []
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(NULL), cout.tie(NULL);
//     return 0;
// }();

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int n, vector<bool> &visited, vector<int> adj[])
    {
        visited[n] = true;
        for (int &u : adj[n])
        {
            if (!visited[u])
                dfs(u, visited, adj);
        }
    }
    int makeConnected(int N, vector<vector<int>> &connections)
    {
        if (N > connections.size() + 1)
        {
            return -1;
        }
        int components = 0;
        vector<bool> visited(N, false);
        vector<int> adj[N];
        int n = connections.size();
        for (int i = 0; i < n; i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, adj);
                components++;
            }
        }
        return components - 1;
    }
};

//? approach 2**************************************************************************************************************************
//! using DSU

static int _star = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    return 0;
}();

class Solution2
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
    void _union(int x, int y, vector<int> &parent, vector<int> &rank, int &cnt)
    {
        int p_x = find(x, parent);
        int p_y = find(y, parent);

        if (p_x == p_y)
        {
            return;
        }
        cnt++;
        if (rank[p_y] > rank[p_x])
        {
            parent[p_x] = p_y;
        }
        else if (rank[p_x] > rank[p_y])
        {
            parent[p_y] = p_x;
        }
        else
        {
            parent[p_x] = p_y;
            rank[p_x]++;
        }
    }

    int makeConnected(int N, vector<vector<int>> &connections)
    {
        if (N > connections.size() + 1)
        {
            return -1;
        }

        vector<int> parent;
        vector<int> rank;

        // maximum components in a graph is always equals to number of nodes
        int components = N;
        int n = connections.size();
        for (int i = 0; i < N; i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }

        int cnt = 0;
        if (N > connections.size() + 1)
        {
            return -1;
        }
        else
        {
            int n = connections.size();
            // for(int i = 0; i < n; i++){
            //     int x = connections[i][0];
            //     int y = connections[i][1];
            //     _union(x,y,parent,rank,cnt);
            // }
            for (int i = 0; i < n; i++)
            {
                int px = find(connections[i][0], parent);
                int py = find(connections[i][1], parent);
                if (px != py)
                {
                    _union(px, py, parent, rank, cnt);
                    components--;
                }
            }
        }
        // minimum required edges are N-1
        // apart from that we have utilized cnt edges that is always cnt <= N-1
        // so we need to return remaining edges!
        // return N-1-cnt;

        return components - 1;
    }
};

int main()
{
    Solution solution;
    // Solution2 solution;
    int N = 6;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {4, 5}};
    cout << "Minimum number of operations to make all computers connected: " << solution.makeConnected(N, connections) << endl;
    return 0;
}