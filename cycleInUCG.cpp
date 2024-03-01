#include <bits/stdc++.h>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

#define pb(a) push_back(a);
using namespace std;

class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool isCycleBFS(vector<int> adj[], vector<bool> &visited, int node, int parent)
    {
        queue<pair<int, int>> q;
        q.push(make_pair(node, parent));
        visited[node] = true;

        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            for (int &it : adj[curr.first])
            {
                if (it == curr.second)
                {
                    continue;
                }
                if (visited[it])
                {
                    return true;
                }
                if (!visited[it])
                {
                    // parent = curr;
                    q.push(make_pair(it, curr.first));
                    visited[it] = true;
                }
            }
        }
        return false;
    }
    bool isCycleDFS(vector<int> adj[], vector<bool> &visited, int node, int parent)
    {
        // wether the node is visited or not is actually checked at the calling function!
        // so no need to check it here

        // if(visited[node] == true){
        //     return false;
        // }

        // just mark it as visited!
        visited[node] = true;

        // and traverse through all the adjacent except parent
        // note that !! parent here is exception!

        for (int &it : adj[node])
        {
            if (it == parent)
            {
                continue;
            }
            if (!(it == parent) && visited[it])
            {
                return true;
            }
            if (isCycleDFS(adj, visited, it, node))
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        // this for loop is helpful to detect cylce even if it is not connected graph!
        // we will simply call dfs on all the nodes!!! yess its as simple as that!
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            // after  dfs call on 1st component most of the nodes will be visited!!
            // so no need to check for them!!
            // simply if it is visited ! skip it and move on the next one!
            // intention of this for loop should be
            // to run exactly what are the # of components in graph!!
            if (!visited[i] && isCycleDFS(adj, visited, i, -1))
            {
                return true;
            }
        }
        return false;
    }
};

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
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}