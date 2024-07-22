#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    bool topologicalSort(int u, unordered_map<int, vector<int>> &adj, vector<bool> &visited, vector<bool> &inRec, stack<int> &st) {
        if (visited[u]) return false;
        visited[u] = inRec[u] = true;

        for (auto &v : adj[u]) {
            if (visited[v] && inRec[v]) {
                return true;
            }
            if (topologicalSort(v, adj, visited, inRec, st)) {
                return true;
            }
        }
        inRec[u] = false;
        st.push(u);
        return false;
    }

    vector<int> utility(vector<vector<int>> v, int k) {
        unordered_map<int, vector<int>> adj;
        vector<int> incomming(k + 1, 0);
        for (auto &vec : v) {
            adj[vec[0]].push_back(vec[1]);
            incomming[vec[1]]++;
        }
        vector<bool> visited(k + 1, false);
        vector<bool> inRec(k + 1, false);
        stack<int> st;
        for (int i = 1; i <= k; i++) {
            if (!visited[i] && topologicalSort(i, adj, visited, inRec, st))
                return {};
        }
        vector<int> row;
        while (!st.empty()) {
            row.push_back(st.top());
            st.pop();
        }
        return row;
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
        // RowConditions
        vector<int> row = utility(rc, k);
        if (row.size() == 0) {
            return {};
        }

        vector<int> col = utility(cc, k);
        if (col.size() == 0) {
            return {};
        }

        unordered_map<int, int> mp;
        for (int i = 0; i < col.size(); i++) {
            mp[col[i]] = i;
        }
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for (int i = 0; i < row.size(); i++) {
            ans[i][mp[row[i]]] = row[i];
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int k = 3;
    vector<vector<int>> rc = {{1, 2}, {2, 3}};
    vector<vector<int>> cc = {{2, 3}, {1, 2}};
    vector<vector<int>> result = solution.buildMatrix(k, rc, cc);

    for (const auto& row : result) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
