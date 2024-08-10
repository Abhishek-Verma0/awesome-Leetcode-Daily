/**959. Regions Cut By Slashes
Solved
Medium
Topics
Companies

An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.

 

Example 1:

Input: grid = [" /","/ "]
Output: 2

Example 2:

Input: grid = [" /","  "]
Output: 1

Example 3:

Input: grid = ["/\\","\\/"]
Output: 5
Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.

 

Constraints:

    n == grid.length == grid[i].length
    1 <= n <= 30
    grid[i][j] is either '/', '\', or ' '.

 */


var regionsBySlashes = function(grid) {
    let n = grid.length * 3;
    let res = 0;
    
    let newGrid = Array(n).fill().map(() => Array(n).fill(0));

    let visit = (i, j) => {
        if (i < 0 || i >= n || j < 0 || j >= n || newGrid[i][j]) return;
        newGrid[i][j] = 1;
        visit(i + 1, j);
        visit(i - 1, j);
        visit(i, j + 1);
        visit(i, j - 1);
    }

    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            let x = i * 3;
            let y = j * 3;

            if (grid[i][j] === '/') {
                newGrid[x][y + 2] = 1;
                newGrid[x + 1][y + 1] = 1;
                newGrid[x + 2][y] = 1;
            } else if (grid[i][j] === '\\') {
                newGrid[x][y] = 1;
                newGrid[x + 1][y + 1] = 1;
                newGrid[x + 2][y + 2] = 1;
            }
        }
    }

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (!newGrid[i][j]) {
                res++;
                visit(i, j);
            }
        }
    }

    return res;
};