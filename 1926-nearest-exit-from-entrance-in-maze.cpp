class Solution {
private:
  static constexpr pair<int, int> deltas[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int rows = maze.size();
    int cols = maze[0].size();
    int steps = 0;

    queue<pair<int, int>> frontier;
    frontier.push({entrance[0], entrance[1]});
    maze[entrance[0]][entrance[1]] = '+';

    while (!frontier.empty()) {
      int level_size = frontier.size();
      ++steps;
      for (int i = 0; i < level_size; ++i) {
        auto [row, col] = frontier.front();
        frontier.pop();
        for (auto [row_delta, col_delta] : deltas) {
          int n_row = row + row_delta;
          int n_col = col + col_delta;
          if (n_row < 0 || n_col < 0 || n_row >= rows || n_col >= cols) continue;
          if (maze[n_row][n_col] != '.') continue;
          if (n_row == 0 || n_col == 0 || n_row == rows - 1 || n_col == cols - 1) return steps;
          frontier.push({n_row, n_col});
          maze[n_row][n_col] = '+';
        }
      }
    }
    return -1;
  }
};
