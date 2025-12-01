class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs(heights, pac, i, 0, heights[i][0]);
            dfs(heights, atl, i, n - 1, heights[i][n - 1]);
        }

        for (int j = 0; j < n; j++) {
            dfs(heights, pac, 0, j, heights[0][j]);
            dfs(heights, atl, m - 1, j, heights[m - 1][j]);
        }

        vector<vector<int>> result;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j, int prev) {
        int m = heights.size();
        int n = heights[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n) return;
        if (visited[i][j]) return;
        if (heights[i][j] < prev) return;

        visited[i][j] = true;

        dfs(heights, visited, i + 1, j, heights[i][j]);
        dfs(heights, visited, i - 1, j, heights[i][j]);
        dfs(heights, visited, i, j + 1, heights[i][j]);
        dfs(heights, visited, i, j - 1, heights[i][j]);
    }
};
