#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool dfs(int node, vector<int>& visited, vector<int>& pathVisited,
             vector<int>& check, vector<vector<int>>& graph) {

        visited[node] = 1;
        pathVisited[node] = 1;

        for (auto it : graph[node]) {
            if (!visited[it]) {
                if (dfs(it, visited, pathVisited, check, graph))
                    return true;
            }
            else if (pathVisited[it] == 1) {
                return true;
            }
        }

        pathVisited[node] = 0;
        check[node] = 1;   // Mark as safe
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();

        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        vector<int> check(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, pathVisited, check, graph);
            }
        }

        vector<int> safeNodes;

        for (int i = 0; i < V; i++) {
            if (check[i] == 1)
                safeNodes.push_back(i);
        }

        return safeNodes;
    }
};

int main() {

    vector<vector<int>> graph = {
        {1, 2},   // 0
        {2, 3},   // 1
        {5},      // 2
        {0},      // 3
        {5},      // 4
        {},       // 5
        {}        // 6
    };

    Solution obj;

    vector<int> ans = obj.eventualSafeNodes(graph);

    cout << "Safe Nodes: ";

    for (auto node : ans)
        cout << node << " ";

    cout << endl;

    return 0;
}