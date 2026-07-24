#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build the graph
        for (auto it : prerequisites) {
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        // Push all courses with indegree 0
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;

                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return topo.size() == numCourses;
    }
};

int main() {
    int numCourses = 4;

    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    Solution obj;

    if (obj.canFinish(numCourses, prerequisites))
        cout << "All courses can be completed." << endl;
    else
        cout << "It is impossible to complete all courses." << endl;

    return 0;
}