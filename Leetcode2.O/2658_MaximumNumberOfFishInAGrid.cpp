

class Solution {
public:
    int m, n;  // Grid dimensions: m rows and n columns
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  // Up, Down, Left, Right

    // DFS function to explore and collect all fish in the current connected region
    int dfs(int i, int j, vector<vector<int>>& grid) {
        // Check if current cell is out of bounds or has no fish (already visited or water)
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }

        // Collect fish from the current cell
        int fishCount = grid[i][j];
        grid[i][j] = 0;  // Mark the cell as visited by setting it to 0

        // Explore all four possible directions (up, down, left, right)
        for (vector<int>& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            // Accumulate fish from all connected cells recursively
            fishCount += dfs(new_i, new_j, grid);
        }

        return fishCount;  // Total fish collected in this connected region
    }

    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();    // Number of rows in the grid
        n = grid[0].size(); // Number of columns in the grid
        int maxFish = 0;    // Track the maximum fish collected in any region

        // Iterate through each cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the cell has fish, initiate DFS to explore the connected region
                if (grid[i][j] > 0) {
                    // Update maxFish with the maximum value found
                    maxFish = max(maxFish, dfs(i, j, grid));
                }
            }
        }

        return maxFish;  // Return the maximum fish collected
    }
};