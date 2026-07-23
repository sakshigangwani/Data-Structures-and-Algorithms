#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    void bfs(int i, int j, int n, int m,
             vector<vector<int>>& visited,
             vector<vector<char>>& grid) {

        visited[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == '1' &&
                    !visited[nrow][ncol]) {

                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    bfs(i, j, n, m, visited, grid);
                }
            }
        }

        return count;
    }
};

int main() {

    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    Solution obj;

    cout << "Number of Islands: " << obj.numIslands(grid) << endl;

    return 0;
}