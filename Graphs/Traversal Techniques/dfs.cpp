#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfsSolve(int node, vector<int>& visited, vector<vector<int>>& adj, vector<int>& ans) {
        visited[node] = 1;
        ans.push_back(node);

        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfsSolve(it, visited, adj, ans);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> visited(V, 0);
        vector<int> ans;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfsSolve(i, visited, adj, ans);
            }
        }

        return ans;
    }
};

int main() {
    // Number of vertices
    int V = 7;

    // Adjacency List
    vector<vector<int>> adj(V);

    // Graph:
    // 0 -- 1
    // |    |
    // 2    3
    //
    // 4 -- 5
    //
    // 6 (isolated)

    adj[0].push_back(1);
    adj[0].push_back(2);

    adj[1].push_back(0);
    adj[1].push_back(3);

    adj[2].push_back(0);

    adj[3].push_back(1);

    adj[4].push_back(5);

    adj[5].push_back(4);

    // adj[6] is isolated

    Solution obj;
    vector<int> ans = obj.dfs(adj);

    cout << "DFS Traversal: ";
    for (int node : ans) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}