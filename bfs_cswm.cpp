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
    void bfs(unordered_map<int, vector<int>> &mp, vector<int> &res, vector<bool> &visited, int v)
    {
        queue<int> q;
        // if an element enters in to queue it means that it has been visited
        q.push(v);
        visited[v] = true;
        res.pb(v);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it = mp[node].begin(); it != mp[node].end(); it++)
            {
                if (!visited[*it])
                {
                    visited[*it] = true;
                    q.push(*it);
                    res.pb(*it);
                }
            }
        }
    }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < V; i++)
        {
            for (int &a : adj[i])
            {
                mp[i].pb(a);
            }
        }
        vector<int> res;
        vector<bool> visited(V, false);
        bfs(mp, res, visited, 0);
        return res;
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
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}