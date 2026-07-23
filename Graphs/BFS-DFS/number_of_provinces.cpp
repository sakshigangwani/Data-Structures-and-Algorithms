#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    void bfs(int node, int n, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node] = 1;

        queue<int> q;
        q.push(node);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int j = 0; j < n; j++) {
                if (isConnected[curr][j] == 1 && !visited[j]) {
                    visited[j] = 1;
                    q.push(j);
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> visited(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                bfs(i, n, isConnected, visited);
            }
        }

        return count;
    }
};

int main() {
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    Solution obj;

    cout << "Number of Provinces: " << obj.findCircleNum(isConnected) << endl;

    return 0;
}