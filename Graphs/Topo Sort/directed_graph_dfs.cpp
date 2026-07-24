#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool dfs(int node, vector<int>& visited, vector<int>& pathVisited, vector<int> adj[]) {
        visited[node] = 1;
        pathVisited[node] = 1;

        for (auto it : adj[node]) {
            if (!visited[it]) {
                if (dfs(it, visited, pathVisited, adj))
                    return true;
            }
            else if (pathVisited[it] == 1) {
                return true;
            }
        }

        pathVisited[node] = 0;
        return false;
    }

public:
    bool isCyclic(int N, vector<int> adj[]) {
        vector<int> visited(N, 0);
        vector<int> pathVisited(N, 0);

        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, pathVisited, adj))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    int N = 4;

    vector<int> adj[N];

    // Directed edges
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);   // Creates a cycle: 1 -> 2 -> 3 -> 1

    Solution obj;

    if (obj.isCyclic(N, adj))
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle Detected" << endl;

    return 0;
}