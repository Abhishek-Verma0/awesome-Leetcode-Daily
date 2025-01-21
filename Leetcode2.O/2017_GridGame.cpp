/**
 * T.C -- O(n)
 * S.C -- O(1)
 */


class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        // Step 1: Calculate the total sum of the first row (all elements initially available)
        long long remainingTopSum = accumulate(begin(grid[0]), end(grid[0]), 0LL); // O(n)
        
        // Step 2: Initialize the sum of the bottom row collected so far (starting from zero)
        long long collectedBottomSum = 0;

        // Step 3: This will store the minimum possible maximum score the second robot can achieve
        long long minMaxScoreForRobot2 = LLONG_MAX;

        // Step 4: Iterate over each column to consider different points where Robot1 can move down
        for (int col = 0; col < grid[0].size(); col++) { // O(n)
            // Robot1 moves down at this column, so subtract the current column's value from the remaining top sum
            remainingTopSum -= grid[0][col];

            // Robot2 will maximize its collection by picking the max of the remaining top sum or collected bottom sum
            long long robot2OptimalChoice = max(remainingTopSum, collectedBottomSum);

            // Update the minimum possible maximum score Robot2 can achieve
            minMaxScoreForRobot2 = min(minMaxScoreForRobot2, robot2OptimalChoice);

            // Add the current bottom row cell to Robot2's collected sum for the next iteration
            collectedBottomSum += grid[1][col];
        }

        return minMaxScoreForRobot2;
    }
};
