//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pb(a) push_back(a)
class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    void TopologicalDFS(vector<int> adj[], int u, vector<bool> &visited, stack<int> &st)
    {
        visited[u] = true;

        for (int &v : adj[u])
        {
            if (!visited[v])
            {
                TopologicalDFS(adj, v, visited, st);
            }
        }
        st.push(u);
    }
    vector<int> TopologicalBFS(vector<int> adj[], int n)
    {
        queue<int> q;
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int &v : adj[i])
            {
                indegree[v]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                // break;
            }
        }
        vector<int> ans;
        // in bfs when a node enters into queue it is marked as visited!
        // visited[node] = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            ans.push_back(u);

            for (int &v : adj[u])
            {
                // if(!visited[v]){
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
                // visited[v] = true;
                // }
            }
        }
        return ans;
    }

    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        vector<bool> visited(V, false);
        stack<int> st;
        vector<int> ans;
        // vector<int>
        // for(int i = 0; i < V; i++){
        // if(!visited[i] ){
        return TopologicalBFS(adj, V);
        //}
        //}
        // vector<int> ans;
        // for( int i = 0; i < V; i++){
        //    // ans.pb(st.top());
        //    // st.pop();
        //    cout<<ans[i]<<" ";
        // }
        // return ans;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<int> adj[])
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
// } Driver Code Ends