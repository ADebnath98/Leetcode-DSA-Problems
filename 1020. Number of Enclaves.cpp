class Solution {
public:
    const vector<int> neighbors{-1, 0, 1, 0, -1};

    void dfs(int i, int j, int m, int n, vector<vector<int>> &grid) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return;

        grid[i][j] = 0;

        for (int k = 0; k < 4; k++) {
            int new_i = i + neighbors[k];
            int new_j = j + neighbors[k + 1];

            dfs(new_i, new_j, m, n, grid);
        }
    }

    int numEnclaves(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        int answer = m * n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;

                if (i != 0 && i != m - 1 && j != 0 && j != n - 1)
                    continue;

                dfs(i, j, m, n, grid);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    continue;

                answer--;
            }
        }

        return answer;
    }
};