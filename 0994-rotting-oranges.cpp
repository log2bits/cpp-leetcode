class Solution {
private:
    static constexpr pair<int, int> deltas[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rotting;

        int fresh = 0;
        int t = 0;

        int rows = grid.size();
        int cols = grid[0].size(); // Fine since grid is not empty

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 2) rotting.push({row, col});
                if (grid[row][col] == 1) ++fresh;
            }
        }

        while (!rotting.empty()) {
            int rotting_count = rotting.size();
            bool rotted = false;
            for (int i = 0; i < rotting_count; ++i) {
                auto [row, col] = rotting.front();
                rotting.pop();
                for (auto [delta_row, delta_col] : deltas) {
                    int n_row = delta_row + row;
                    int n_col = delta_col + col;
                    if (n_row < 0 || n_col < 0 || n_row >= rows || n_col >= cols) continue;
                    if (grid[n_row][n_col] == 1) {
                        grid[n_row][n_col] = 2;
                        rotting.push({n_row, n_col});
                        rotted = true;
                        --fresh;
                    }
                }
            }
            if (rotted) ++t;
        }

        return fresh == 0 ? t : -1;
    }
};
