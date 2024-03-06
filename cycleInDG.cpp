#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
//----------TEMPLATES----------
// template <typename... T>
// void see(T &...args) { ((cin >> args), ...); }
// template <typename... T>
// void put(T &&...args) { ((cout << args << " "), ...); }
// template <typename... T>
// void putl(T &&...args)
// {
//     ((cout << args << " "), ...);
//     cout << '\n';
// }
// #define error(args...)                           \
//     {                                            \
//         string _s = #args;                       \
//         replace(_s.begin(), _s.end(), ',', ' '); \
//         stringstream _ss(_s);                    \
//         istream_iterator<string> _it(_ss);       \
//         err(_it, args);                          \
//     }
// void err(istream_iterator<string> it) {}
// template <typename T, typename... Args>
// void err(istream_iterator<string> it, T a, Args... args)
// {
//     cerr << *it << "=" << a << ", ";
//     err(++it, args...);
// }
//----------MACROS----------
// #define int long long
// #define pb push_back
// #define F first
// #define S second
// #define ll long long
// #define ull unsigned long long
// #define ld long double
// #define pii pair<int, int>
// #define vi vector<int>
// #define vii vector<pii>
// #define vc vector
// #define nl cout << '\n'
// #define E cerr << '\n'
// #define all(x) x.begin(), x.end()
// #define rep(i, a, b) for (int i = a; i < b; ++i)
// #define rev(i, a, b) for (int i = a; i > b; --i)
// #define IOS ios_base::sync_with_stdio(false)
// #define setpr(x) cout << setprecision(x) << fixed
// #define sz size()
// #define seea(a, x, y)           \
//     for (int i = x; i < y; i++) \
//     {                           \
//         cin >> a[i];            \
//     }
// #define seev(v, n)              \
//     for (int i = 0; i < n; i++) \
//     {                           \
//         int x;                  \
//         cin >> x;               \
//         v.push_back(x);         \
//     }
// #define sees(s, n)              \
//     for (int i = 0; i < n; i++) \
//     {                           \
//         int x;                  \
//         cin >> x;               \
//         s.insert(x);            \
//     }
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
//----------CONSTANTS----------
// const ll inf = INT_MAX;
// const ld ep = 0.0000001;
// const ld pi = acos(-1.0);
// const ll md = 1000000007;
//----------GLOBALS----------

//----------SOLUTION----------

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pb(a) push_back(a)
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool DFS(vector<int> adj[], int u, vector<bool> &visited, vector<bool> &inRecursion)
    {
        visited[u] = true;
        inRecursion[u] = true;

        for (int &v : adj[u])
        {
            if (visited[v] && inRecursion[v])
            {
                return true;
            }
            if (!visited[v] && DFS(adj, v, visited, inRecursion))
            {
                return true;
            }
        }
        inRecursion[u] = false;
        return false;
    }
    bool BFSIsCycle(vector<int> adj[], int &V, vector<bool> &visited)
    {
        queue<int> q;
        // vector<int> ans;

        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (int &a : adj[i])
            {
                indegree[a]++;
            }
        }
        bool flg = false;
        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            // for(int j = 0; j < adj[i].length(); j++){
            if (indegree[i] == 0)
            {
                q.push(i);
                visited[i] == true;
                flg = true;
                cnt++;
            }
            // }
        }
        if (!flg)
        {
            return true;
        }
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            // ans.pb(v);
            for (int &a : adj[v])
            {
                indegree[a]--;
                if (indegree[a] == 0)
                {
                    q.push(a);
                    visited[a] = true;
                    cnt++;
                }
            }
        }
        if (cnt == V)
        {
            return false;
        }
        else
        {
            return true;
        }
        // return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<bool> visited(V, false);
        // vector<bool> inRecursion(V,false);
        for (int i = 0; i < V; i++)
        {
            // if(!visited[i] && DFS(adj,i,visited,inRecursion)){
            //     return true;
            // }
            if (!visited[i] && BFSIsCycle(adj, V, visited))
                return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends