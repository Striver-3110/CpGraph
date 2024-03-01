// #include <bits/stdc++.h>
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
class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &result, unordered_map<int, vector<int>> &mp)
    {
        if (visited[node] == true)
        {
            // vector<int> arr;
            return;
        }
        visited[node] = true;
        result.pb(node);
        // vector<int> arr = adj[node];
        vector<int> arr = mp[node];

        for (int &a : arr)
        {
            if (visited[a] != true)
            {
                dfs(a, adj, visited, result, mp);
            }
        }
        return;
        // return result;
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < V; i++)
        {
            for (auto it = adj[i].begin(); it != adj[i].end(); it++)
            {
                mp[i].pb(*it);
            }
        }
        vector<int> result;
        vector<bool> visited(V, false);
        dfs(0, adj, visited, result, mp);
        return result;
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
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}