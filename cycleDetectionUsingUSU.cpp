//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pb(a) push_back(a);
class Solution
{
public:
    // Function to detect cycle using DSU in an undirected graph.
    int find(int i, vector<int> &parent)
    {
        if (i == parent[i])
        {
            return i;
        }
        return parent[i] = find(parent[i], parent);
    }

    bool _union(int u, int v, vector<int> &parent, vector<int> &rank)
    {

        // finding parent for both u and v
        // in order to group them
        int parent_u = find(u, parent);
        int parent_v = find(v, parent);

        // if both have same parent that means...
        // both of them belongs to same gorup!
        if (parent_u == parent_v)
        {
            return true;
        }

        // rank helps to keep the hight of the graph as small as possible

        // rank is high means that that parent have deeper graph then the parent having lower rank
        if (rank[parent_u] > rank[parent_v])
        {
            parent[parent_v] = parent_u;
        }
        else if (rank[parent_u] < rank[parent_v])
        {
            parent[parent_u] = parent_v;
        }
        else
        {
            parent[parent_u] = parent_v;
            rank[parent_u]++;
        }
        return false;
    }
    int detectCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> parent;
        vector<int> rank;
        for (int i = 0; i < V; i++)
        {
            parent.pb(i);
            rank.pb(0);
        }
        for (int u = 0; u < V; u++)
        {
            for (int v : adj[u])
            {
                // as it is un direcred graph
                // we are not required to visit the sane edge twice!
                if (u < v)
                {
                    if (_union(u, v, parent, rank) == true)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        int ans = obj.detectCycle(V, adj);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends