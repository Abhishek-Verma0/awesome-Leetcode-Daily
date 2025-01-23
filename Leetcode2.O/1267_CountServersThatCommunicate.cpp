/**
 * T.C -- O(n*m)
 * S.C -- O(n+m)
 */


class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();       // Number of rows
        int m = grid[0].size();     // Number of columns
        
        // Vectors to store count of servers in each row and each column
        vector<int> rowCount(n, 0);
        vector<int> colCount(m, 0); // FIXED: Use 'm' instead of 'n' for columns

        // Step 1: Count servers in each row and column
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(grid[row][col]) {  // If there is a server at (row, col)
                    rowCount[row]++;  // Increase row count
                    colCount[col]++;  // Increase column count
                }
            }
        }

        int res = 0;

        // Step 2: Check if the server can communicate with another
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(grid[row][col]) {  // If there's a server at (row, col)
                    // If there is more than one server in the row or column, count it
                    if(rowCount[row] > 1 || colCount[col] > 1) {
                        res++;
                    }
                }
            }
        }

        return res; // Return the total count of communicating servers
    }
};
