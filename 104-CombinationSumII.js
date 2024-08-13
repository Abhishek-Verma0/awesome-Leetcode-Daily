/**40. Combination Sum II
Solved
Medium
Topics
Companies

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

 

Constraints:

    1 <= candidates.length <= 100
    1 <= candidates[i] <= 50
    1 <= target <= 30

 */



/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
function combinationSum2(candidates, target) {
    const results = [];
    candidates.sort((a, b) => a - b); // Sort the array to handle duplicates easily

    function backtrack(remainingSum, start, path) {
        if (remainingSum === 0) {
            results.push([...path]); // Found a valid combination
            return;
        }

        for (let i = start; i < candidates.length; i++) {
            if (i > start && candidates[i] === candidates[i - 1]) {
                continue; // Skip duplicates
            }

            if (candidates[i] > remainingSum) {
                break; // No point in continuing as the array is sorted
            }

            path.push(candidates[i]);
            backtrack(remainingSum - candidates[i], i + 1, path);
            path.pop(); // Backtrack
        }
    }

    backtrack(target, 0, []);
    return results;
}

