/***689. Maximum Sum of 3 Non-Overlapping Subarrays
Solved
Hard
Topics
Companies

Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

 

Example 1:

Input: nums = [1,2,1,2,6,7,5,1], k = 2
Output: [0,3,5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.

Example 2:

Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
Output: [0,2,4]

 

Constraints:

    1 <= nums.length <= 2 * 104
    1 <= nums[i] < 216
    1 <= k <= floor(nums.length /  */




class Solution {
private:
    // Memoization table to store intermediate results
    int t[20001][4];

    // Recursive helper function to calculate the maximum sum
    int helper(vector<int>& sums, int k, int idx, int rem) {
        // Base case: if no subarrays are left to pick, return 0
        if (rem == 0) return 0;

        // If we've reached the end of the sums array, return negative infinity
        // because no valid subarray can be formed
        if (idx >= sums.size()) {
            return INT_MIN;
        }

        // If the result is already computed, return it
        if (t[idx][rem] != -1) {
            return t[idx][rem];
        }

        // Option 1: Take the current subarray and move `k` steps forward
        int take = sums[idx] + helper(sums, k, idx + k, rem - 1);

        // Option 2: Skip the current subarray and move 1 step forward
        int not_take = helper(sums, k, idx + 1, rem);

        // Store the maximum of the two options in the memoization table
        t[idx][rem] = max(take, not_take);
        return t[idx][rem];
    }

    // Function to reconstruct the indices of the chosen subarrays
    void solve(vector<int>& sums, int k, int idx, int rem, vector<int>& indices) {
        // Base case: if no subarrays are left to pick, return
        if (rem == 0) return;

        // If we've reached the end of the sums array, return
        if (idx >= sums.size()) return;

        // Calculate the two options using the helper function
        int take = sums[idx] + helper(sums, k, idx + k, rem - 1);
        int not_take = helper(sums, k, idx + 1, rem);

        // Choose the option that gives the maximum result
        if (take >= not_take) {
            indices.push_back(idx); // Add the current index to the result
            solve(sums, k, idx + k, rem - 1, indices); // Move `k` steps forward
        } else {
            solve(sums, k, idx + 1, rem, indices); // Move 1 step forward
        }
    }

public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        // Initialize the memoization table with -1
        memset(t, -1, sizeof(t));

        // Calculate the number of possible subarray starting positions
        int n = nums.size() - k + 1;

        // Array to store the sums of all subarrays of size `k`
        vector<int> sums;
        int windowSum = 0;
        int i = 0, j = 0;

        // Use sliding window to calculate the sums of all subarrays of size `k`
        while (j < nums.size()) {
            windowSum += nums[j]; // Add the current element to the window sum
            
            // When the window size is exactly `k`, store the sum
            if (j - i + 1 == k) {
                sums.push_back(windowSum); // Store the sum of the current window
                windowSum -= nums[i];     // Remove the first element of the window
                i++; // Slide the window forward
            }
            j++;
        }

        vector<int> indices; // To store the indices of the selected subarrays

        // Reconstruct the path to find the indices of the subarrays
        solve(sums, k, 0, 3, indices);

        return indices; // Return the indices of the subarrays
    }
};
