#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void bfs(int node, vector<int>& visited, vector<vector<int>>& adj) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto it : adj[curr]) {
                if (!visited[it]) {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
    }

    int findNumberOfComponent(int V, vector<vector<int>>& edges) {

        // Create adjacency list
        vector<vector<int>> adj(V);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(V, 0);

        int count = 0;

        // Traverse all vertices
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                bfs(i, visited, adj);
            }
        }

        return count;
    }
};

int main() {

    int V = 7;

    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {3, 4},
        {5, 6}
    };

    Solution obj;

    cout << "Number of Connected Components: "
         << obj.findNumberOfComponent(V, edges) << endl;

    return 0;
}