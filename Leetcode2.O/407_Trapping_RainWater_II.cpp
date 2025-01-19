



// T.C: O(m * n * log(m * n))
// S.C: O(m * n)
class Solution {
public:
    typedef pair<int, pair<int, int>> Cell; // Represents a cell as {height, {row, col}}
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Right, Down, Left, Up  to store the directions where to move 

    int trapRainWater(vector<vector<int>>& heightMap) {
        int rows = heightMap.size();          // Number of rows
        int cols = heightMap[0].size();       // Number of columns

        // Min-heap to process boundary cells based on their height
        priority_queue<Cell, vector<Cell>, greater<>> boundaryCells;

        // Visited matrix to keep track of cells already processed
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Push the boundary cells (first and last columns for each row)
        for (int row = 0; row < rows; ++row) {
            for (int col : {0, cols - 1}) { // First and last columns
                boundaryCells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true; // Mark as visited
            }
        }

        // Push the boundary cells (first and last rows for each column)
        for (int col = 0; col < cols; ++col) {
            for (int row : {0, rows - 1}) { // First and last rows
                boundaryCells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true; // Mark as visited
            }
        }

        int totalTrappedWater = 0; // Variable to store the total trapped water

        // Process cells in the priority queue
        while (!boundaryCells.empty()) {
            auto [currHeight, cell] = boundaryCells.top();
            boundaryCells.pop(); // Extract the cell with the lowest height

            int currRow = cell.first;
            int currCol = cell.second;

            // Explore all 4 directions (right, down, left, up)
            for (vector<int>& dir : directions) {
                int newRow = currRow + dir[0];
                int newCol = currCol + dir[1];

                // Check if the new cell is within bounds and not visited
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && !visited[newRow][newCol]) {
                    
                    // Calculate trapped water at the new cell
                    totalTrappedWater += max(0, currHeight - heightMap[newRow][newCol]);
                    
                    // Push the cell into the queue with updated height
                    boundaryCells.push({max(currHeight, heightMap[newRow][newCol]), {newRow, newCol}});
                    
                    // Mark the new cell as visited
                    visited[newRow][newCol] = true;
                }
            }
        }

        return totalTrappedWater; // Return the total trapped water
    }
};
