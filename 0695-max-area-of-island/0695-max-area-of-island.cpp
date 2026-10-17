class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool valid(int row, int col, int i, int j) {
        return !(i < 0 || i >= row || j < 0 || j >= col);
    }

    int dfs(vector<vector<int>>& grid, int m, int n,
            int i, int j, vector<vector<bool>>& vis) {

        vis[i][j] = true;

        int area = 1; 

        for (int k = 0; k < 4; k++) {
            int row = i + x[k];
            int col = j + y[k];

            if (valid(m, n, row, col) &&
                grid[row][col] == 1 &&
                !vis[row][col]) {

                area += dfs(grid, m, n, row, col, vis);
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1 && !vis[i][j]) {
                    int area = dfs(grid, m, n, i, j, vis);
                    res = max(res, area);
                }
            }
        }

        return res;
    }
};