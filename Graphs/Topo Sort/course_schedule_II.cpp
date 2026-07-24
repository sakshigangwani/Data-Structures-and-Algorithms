#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build the graph
        for (auto it : prerequisites) {
            int first = it[0];
            int second = it[1];

            adj[second].push_back(first);
            indegree[first]++;
        }

        // Push all courses with indegree 0
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;

                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        if (ans.size() == numCourses)
            return ans;

        return {};
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

    vector<int> order = obj.findOrder(numCourses, prerequisites);

    if (order.empty()) {
        cout << "No valid course order exists." << endl;
    } else {
        cout << "Course Order: ";
        for (int course : order) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}