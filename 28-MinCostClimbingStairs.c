/*746. Min Cost Climbing Stairs
Solved
Easy
Topics
Companies
Hint

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.

 

Constraints:

    2 <= cost.length <= 1000
    0 <= cost[i] <= 999

*/






#include <stdio.h>

int minCostClimbingStairs(int* cost, int costSize) {
    if (costSize == 0) return 0;
    if (costSize == 1) return cost[0];
    
    int prev1 = cost[1]; // Cost to step on the 1st step
    int prev2 = cost[0]; // Cost to step on the 0th step

    for (int i = 2; i < costSize; i++) {
        int current = cost[i] + (prev1 < prev2 ? prev1 : prev2);
        prev2 = prev1;
        prev1 = current;
    }
    
    // Return the minimum cost to reach the top, which can be from the last step or one step before the last.
    return prev1 < prev2 ? prev1 : prev2;
}

int main() {
    int cost[] = {10, 15, 20};
    int costSize = sizeof(cost) / sizeof(cost[0]);
    printf("Minimum cost to climb stairs: %d\n", minCostClimbingStairs(cost, costSize));
    return 0;
}
