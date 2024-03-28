//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int dijskstra(vector<pair<int, int>> adj[], int node, int n, int maxDist)
    {
        int dist[n];
        for (int i = 0; i < n; i++)
        {
            dist[i] = maxDist + 2;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int src = node;
        pq.push({0, src});

        dist[node] = 0;
        while (!pq.empty())
        {
            int prevNode = pq.top().second;
            int prevDist = pq.top().first;

            pq.pop();

            if (prevDist > maxDist)
            {
                continue;
            }

            for (auto it : adj[prevNode])
            {
                int nextDist = it.second;
                int nextNode = it.first;

                if (dist[nextNode] > nextDist + prevDist)
                {
                    dist[nextNode] = nextDist + prevDist;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (i == node)
                continue;

            if (dist[i] <= maxDist)
            {
                cnt++;
            }
        }

        return cnt;
    }
    int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<pair<int, int>> adj[n];

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        set<pair<int, int>> st;
        for (int i = 0; i < n; i++)
        {
            int cnt = dijskstra(adj, i, n, distanceThreshold);
            st.insert({cnt, -i});
        }

        auto it = st.begin();
        pair<int, int> pt = *it;

        return -pt.second;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends