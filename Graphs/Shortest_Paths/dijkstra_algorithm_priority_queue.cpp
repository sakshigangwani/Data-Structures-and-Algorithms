#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <functional>

using namespace std;

vector<int> dijkstra(int V, vector<vector<int>>& edges, int S) {

    // Adjacency List
    vector<vector<pair<int, int>>> adj(V);

    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});   // Undirected Graph
    }

    const long long INF = LLONG_MAX;

    vector<long long> dist(V, INF);

    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;

    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {

        long long distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Ignore stale entries
        if (distance > dist[node])
            continue;

        for (auto& it : adj[node]) {

            int adjNode = it.first;
            int wt = it.second;

            // Relaxation
            if (dist[adjNode] > distance + wt) {

                dist[adjNode] = distance + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    vector<int> ans(V);

    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            ans[i] = 1000000000;
        else
            ans[i] = (int)dist[i];
    }

    return ans;
}

int main() {

    int V = 4;
    int S = 0;

    vector<vector<int>> edges = {
        {0, 1, 1},
        {0, 2, 4},
        {1, 2, 2},
        {1, 3, 6},
        {2, 3, 3}
    };

    vector<int> shortestDistance = dijkstra(V, edges, S);

    cout << "Shortest Distance from Source " << S << ":\n";

    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " : " << shortestDistance[i] << endl;
    }

    return 0;
}