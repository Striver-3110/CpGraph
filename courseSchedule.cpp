static int __star = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    return 0;
}();
#define pb(a) push_back(a)

class Solution
{
public:
    bool dfsCycle(vector<int> adj[], vector<bool> &visited, vector<bool> &inStack, int n)
    {
        // if(adj[n].size() == 0){
        //     return false;
        // }
        visited[n] = true;
        inStack[n] = true;
        for (int &v : adj[n])
        {
            // if(v == parent){
            //     continue;
            // }
            if (!visited[v] && dfsCycle(adj, visited, inStack, v))
            {
                return true;
            }
            if (visited[v] && inStack[v])
            {
                return true;
            }
        }
        inStack[n] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>> &a)
    {
        // int n =  numCOurses;
        vector<int> adj[n];
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){

        //     }
        // }
        for (int i = 0; i < a.size(); i++)
        {
            adj[a[i][1]].pb(a[i][0]);
        }
        vector<bool> visited(n, false);
        vector<bool> inStack(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dfsCycle(adj, visited, inStack, i))
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};
    bool result = solution.canFinish(numCourses, prerequisites);

    if (result)
    {
        cout << "It is possible to finish all courses." << endl;
    }
    else
    {
        cout << "It is not possible to finish all courses due to cyclic dependencies." << endl;
    }

    return 0;
}
