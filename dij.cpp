#include <iostream>
#include <vector>
#include <set>
#include <utility>

const int inf = 1e7;

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        g[v].push_back({u, w});
        g[u].push_back({v, w});
    }

    std::set<std::pair<int, int>> sol;
    std::vector<int> dist(n + 1, inf);
    int src;
    std::cin >> src;
    dist[src] = 0;
    sol.insert({src, 0});
    while (!sol.empty())
    {
        auto prev = *sol.begin();
        sol.erase(prev);
        for (auto curr : g[prev.first])
        {
            if (dist[curr.first] > prev.second + curr.second)
            {
                dist[curr.first] = prev.second + curr.second;
                sol.insert({curr.first, dist[curr.first]});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        std::cout << "Distance from source to node " << i << ": " << dist[i] << std::endl;
    }

    return 0;
}
