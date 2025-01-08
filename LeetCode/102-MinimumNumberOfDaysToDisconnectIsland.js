/**1568. Minimum Number of Days to Disconnect Island
Hard
Topics
Companies
Hint

You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.

The grid is said to be connected if we have exactly one island, otherwise is said disconnected.

In one day, we are allowed to change any single land cell (1) into a water cell (0).

Return the minimum number of days to disconnect the grid.

 

Example 1:

Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]

Output: 2
Explanation: We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.

Example 2:

Input: grid = [[1,1]]
Output: 2
Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 30
    grid[i][j] is either 0 or 1.

 */



var minDays = function(grid) {
    const n = grid.length;
    const m = grid[0].length;

    // Direction vectors for traversing the grid
    const directions = [
        [-1, 0], [1, 0], [0, -1], [0, 1]
    ];

    const isInBounds = (i, j) => i >= 0 && i < n && j >= 0 && j < m;

    // A utility function for DFS traversal to count the number of islands
    const dfs = (i, j, grid, visited) => {
        visited[i][j] = true;

        for (const [di, dj] of directions) {
            const ni = i + di;
            const nj = j + dj;
            if (isInBounds(ni, nj) && grid[ni][nj] === 1 && !visited[ni][nj]) {
                dfs(ni, nj, grid, visited);
            }
        }
    };

    const countIslands = (grid) => {
        const visited = Array.from({ length: n }, () => Array(m).fill(false));
        let islandCount = 0;

        for (let i = 0; i < n; i++) {
            for (let j = 0; j < m; j++) {
                if (grid[i][j] === 1 && !visited[i][j]) {
                    islandCount++;
                    if (islandCount > 1) return islandCount;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return islandCount;
    };

    // Case 0: Check if the grid is already disconnected
    if (countIslands(grid) !== 1) return 0;

    // Case 1: Try removing one cell
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (grid[i][j] === 1) {
                grid[i][j] = 0;
                if (countIslands(grid) !== 1) return 1;
                grid[i][j] = 1;
            }
        }
    }

    // Case 2: If removing one cell doesn't work, it takes two cells
    return 2;
};

