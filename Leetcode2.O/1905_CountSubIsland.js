/**1905. Count Sub Islands
Medium
Topics
Companies
Hint

You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.

 

Example 1:

Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.

Example 2:

Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2 
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.

 

Constraints:

    m == grid1.length == grid2.length
    n == grid1[i].length == grid2[i].length
    1 <= m, n <= 500
    grid1[i][j] and grid2[i][j] are either 0 or 1.

 */



var countSubIslands = function(grid1, grid2) {
    const numRows = grid2.length;
    const numCols = grid2[0].length;
    const totalCells = numRows * numCols;
    const islandRoot = Array.from({ length: totalCells }, (_, i) => i);
    const islandStatus = new Uint8Array(totalCells);

    // Union islands in grid2
    for (let row = 0; row < numRows; row++) {
        for (let col = 0; col < numCols; col++) {
            if (grid2[row][col] === 1) {
                const currentIndex = row * numCols + col;
                if (col + 1 < numCols && grid2[row][col + 1] === 1) {
                    unionIslands(islandRoot, currentIndex, currentIndex + 1);
                }
                if (row + 1 < numRows && grid2[row + 1][col] === 1) {
                    unionIslands(islandRoot, currentIndex, currentIndex + numCols);
                }
            }
        }
    }

    // Mark invalid sub-islands
    for (let row = 0; row < numRows; row++) {
        for (let col = 0; col < numCols; col++) {
            if (grid2[row][col] === 1 && grid1[row][col] === 0) {
                const rootIndex = findIslandRoot(islandRoot, row * numCols + col);
                islandStatus[rootIndex] = 2; // Mark as invalid sub-island
            }
        }
    }

    // Count valid sub-islands
    let subIslandCount = 0;
    for (let row = 0; row < numRows; row++) {
        for (let col = 0; col < numCols; col++) {
            if (grid2[row][col] === 1) {
                const rootIndex = findIslandRoot(islandRoot, row * numCols + col);
                if (islandStatus[rootIndex] === 0) {
                    subIslandCount++;
                    islandStatus[rootIndex] = 1; // Mark as counted
                }
            }
        }
    }

    return subIslandCount;
};

function findIslandRoot(islandRoot, x) {
    if (islandRoot[x] !== x) {
        islandRoot[x] = findIslandRoot(islandRoot, islandRoot[x]); // Path compression
    }
    return islandRoot[x];
}

function unionIslands(islandRoot, x, y) {
    const rootX = findIslandRoot(islandRoot, x);
    const rootY = findIslandRoot(islandRoot, y);
    if (rootX !== rootY) {
        islandRoot[rootY] = rootX;
    }
}
