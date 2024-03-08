#include <bits/stdc++.h>
using namespace std;

// static int __star = [];

// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(NULL), cout.tie(NULL);
//     return 0;
// }
// ();

#define pb(a) push_back(a)

class Solution
{
public:
    void bfsTopological(vector<int> adj[], vector<int> &inDegree,
                        vector<int> &res, int n)
    {
        vector<bool> visited(n, false);
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
                visited[i] = true;
            }
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            res.pb(u);
            for (int &v : adj[u])
            {

                inDegree[v]--;
                if (inDegree[v] == 0)
                {
                    q.push(v);
                }
                // visited[v] = true;
            }
        }
    }
    vector<int> findOrder(int n, vector<vector<int>> &g)
    {
        vector<int> adj[n];
        vector<int> inDegree(n, 0);
        for (int i = 0; i < g.size(); i++)
        {
            adj[g[i][1]].pb(g[i][0]);
            inDegree[g[i][0]]++;
        }

        vector<int> res;

        bfsTopological(adj, inDegree, res, n);
        if (res.size() != n)
        {
            vector<int> mt;
            return mt;
        }
        return res;
    }
};

int main()
{
    // Example usage of the Solution class
    Solution solution;

    // Number of nodes in the graph
    int n = 4;

    // Example input: a list of directed edges
    // Here, the edges are represented as pairs [a, b], where there is a directed edge from a to b
    std::vector<std::vector<int>> edges = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    // Find the topological order
    std::vector<int> result = solution.findOrder(n, edges);

    // Display the result
    if (result.empty())
    {
        std::cout << "No valid topological order exists (graph has a cycle).\n";
    }
    else
    {
        std::cout << "Topological Order: ";
        for (int node : result)
        {
            std::cout << node << " ";
        }
        std::cout << "\n";
    }

    return 0;
}