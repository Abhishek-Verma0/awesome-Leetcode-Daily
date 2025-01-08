/**840. Magic Squares In Grid
Medium
Topics
Companies

A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

 

Example 1:

Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:

while this one is not:

In total, there is only one magic square inside the given grid.

Example 2:

Input: grid = [[8]]
Output: 0

 

Constraints:

    row == grid.length
    col == grid[i].length
    1 <= row, col <= 10
    0 <= grid[i][j] <= 15

 */


/**
 * @param {number[][]} grid
 * @return {number}
 */
var numMagicSquaresInside = function(grid) {
    const row = grid.length;
    const col = grid[0].length;

    if (row < 3 || col < 3) return 0;

    const isValid = (matrix) => {
        // Special case of 5 in center
        if (matrix[1][1] !== 5) {
            return false; 
        }

        // Verify Distinct and Row Sum
        const visited = {};
        let expectedSum = 0;
        for (let i = 0; i < 3; i++) {
            let sum = 0;
            for (let j = 0; j < 3; j++) {
                if (matrix[i][j] >= 1 && matrix[i][j] <= 9 && !visited[matrix[i][j]]) {
                    visited[matrix[i][j]] = true;
                } else {
                    return false;
                }
                sum += matrix[i][j];
            }
            if (i === 0) expectedSum = sum;

            if (sum !== expectedSum) {
                return false;
            } 
        }

        // Verify Col Sum
        for (let j = 0; j < 3; j++) {
            let sum = 0;
            for (let i = 0; i < 3; i++) {
                sum += matrix[i][j];
            }
            if (sum !== expectedSum) {
                return false;
            }
        }

        // Verify Diagonal Sum
        let sumA = 0, sumB = 0;
        for (let i = 0; i < 3; i++) {
            sumA += matrix[i][i];
            sumB += matrix[i][2-i];
        }
        if (sumA !== expectedSum || sumB !== expectedSum) {
            return false;
        }

        return true;
    }

    let answer = 0;
    for (let i = 0; i <= row-3; i++) {
        const m = grid.slice(i, i+3);
        for (let j = 0; j <= col-3; j++) {
            if (isValid(m.map(o => o.slice(j, j+3)))) {
                answer++;
            }
        }
    }

    return answer;
};