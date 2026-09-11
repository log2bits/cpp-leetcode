class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == '1') {
                    ++islands;
                    erase_island(grid, row, col);
                }
            }
        }
        return islands;
    }
private:
    static constexpr pair<int, int> deltas[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void erase_island(vector<vector<char>>& grid, int row, int col) {
        int rows = grid.size();
        int cols = grid[0].size();

        stack<pair<int, int>> land;
        grid[row][col] = '0';
        land.push({row, col});

        while (!land.empty()) {
            auto [land_row, land_col] = land.top();
            land.pop();

            for (auto [row_delta, col_delta] : deltas) {
                int n_row = land_row + row_delta;
                int n_col = land_col + col_delta;
                if (n_row < 0 || n_row >= rows || n_col < 0 || n_col >= cols) continue;
                if (grid[n_row][n_col] == '1') {
                    grid[n_row][n_col] = '0';
                    land.push({n_row, n_col});
                }
            }
        }
    }
};
