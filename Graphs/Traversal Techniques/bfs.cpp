#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void bfs(int node, vector<vector<int>> &adj, vector<int>& visited, vector<int>& ans) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;

        while (!q.empty()) {
            int n = q.front();
            q.pop();
            ans.push_back(n);

            for (auto it : adj[n]) {
                if (!visited[it]) {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
    }

    vector<int> bfs(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> visited(V, 0);
        vector<int> ans;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                bfs(i, adj, visited, ans);
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
    vector<int> ans = obj.bfs(adj);

    cout << "BFS Traversal: ";
    for (int node : ans) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}