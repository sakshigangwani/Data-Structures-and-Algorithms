#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
private:
    void bfs(int node, vector<vector<int>>& adj, vector<int>& dist, int N)
    {
        dist[node] = 0;

        queue<pair<int, int>> q;
        q.push({node, 0});

        while (!q.empty())
        {
            int n = q.front().first;
            int d = q.front().second;
            q.pop();

            for (auto it : adj[n])
            {
                if (dist[it] > d + 1)
                {
                    dist[it] = d + 1;
                    q.push({it, d + 1});
                }
            }
        }
    }

public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M)
    {
        vector<vector<int>> adj(N);

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(N, INT_MAX);

        bfs(0, adj, dist, N);

        for (int i = 0; i < N; i++)
        {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }

        return dist;
    }
};

int main()
{
    // Number of vertices
    int N = 9;

    // Number of edges
    int M = 10;

    // Hardcoded edges
    vector<vector<int>> edges = {
        {0,1},
        {0,3},
        {1,2},
        {1,4},
        {2,5},
        {3,4},
        {4,5},
        {4,6},
        {5,7},
        {6,8}
    };

    Solution obj;

    vector<int> ans = obj.shortestPath(edges, N, M);

    cout << "Shortest distance from source node 0:\n";

    for (int i = 0; i < N; i++)
    {
        cout << "Node " << i << " -> " << ans[i] << endl;
    }

    return 0;
}