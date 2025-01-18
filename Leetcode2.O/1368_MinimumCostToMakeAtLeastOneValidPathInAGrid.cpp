



class Solution {
public:
    // Direction vectors to move right, left, down, and up
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(); // Number of rows in the grid
        int n = grid[0].size(); // Number of columns in the grid

        // Priority queue (min-heap) to store cells as {cost, row, column}
        // Automatically sorts by the first element (cost) in ascending order
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        // 2D vector to store the minimum cost to reach each cell
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        // Start at the top-left corner (0, 0) with a cost of 0
        pq.push({0, 0, 0});
        result[0][0] = 0;

        // Time Complexity: O(m * n * log(m * n))
        // Space Complexity: O(m * n)
        while (!pq.empty()) {
            auto curr = pq.top(); // Get the cell with the smallest cost
            pq.pop(); // Remove it from the queue (logarithmic time complexity)

            int currCost = curr[0]; // Current cost to reach this cell
            int i = curr[1]; // Current row
            int j = curr[2]; // Current column

            // If we already found a cheaper way to this cell, skip it
            if (result[i][j] < currCost) {
                continue;
            }

            // Explore all 4 possible directions
            for (int dir_i = 0; dir_i <= 3; dir_i++) {
                int i_ = i + dir[dir_i][0]; // New row
                int j_ = j + dir[dir_i][1]; // New column

                // Check if the new cell is within grid bounds
                if (i_ >= 0 && j_ >= 0 && i_ < m && j_ < n) {
                    int gridDir = grid[i][j]; // Current grid's arrow direction
                    // Calculate the cost of moving in this direction
                    // If the arrow matches the direction, cost is 0; otherwise, it's 1
                    int dirCost = ((gridDir - 1 != dir_i) ? 1 : 0);

                    int newCost = currCost + dirCost; // Total cost to reach the new cell

                    // If this new cost is smaller than the previously recorded cost
                    if (newCost < result[i_][j_]) {
                        result[i_][j_] = newCost; // Update the cost
                        pq.push({newCost, i_, j_}); // Add the new cell to the queue
                    }
                }
            }
        }

        // Return the minimum cost to reach the bottom-right corner (m-1, n-1)
        return result[m - 1][n - 1];
    }
};
