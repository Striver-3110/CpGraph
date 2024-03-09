#include <iostream>
#include <vector>

using namespace std;

// static int __star = [] {
//     ios_base::sync_with_stdio(0);
//     cin.tie(NULL), cout.tie(NULL);
//     return 0;
// }();

class Solution
{
public:
    bool dfs(vector<vector<int>> &adj, vector<int> &c,
             int node, int nc)
    {
        c[node] = nc;
        // visited[node] = true;

        for (int &a : adj[node])
        {
            if (c[node] == c[a])
            {
                return false;
            }
            if (c[a] == -1)
            {
                nc = 1 - c[node];
                if (!dfs(adj, c, a, nc))
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> c(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (c[i] == -1 && !dfs(adj, c, i, 1))
            {
                return false;
            }
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
