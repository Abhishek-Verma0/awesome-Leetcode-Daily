/**
 * T.C -- O(n^2)
 * S.C -- O(1)
 */


class Solution {
public:
    // Stores the result triplets
    vector<vector<int>> res;

    // Function to find pairs of numbers that sum up to the target using the two-pointer approach
    void twoSum(int i, vector<int>& nums, int j, int target) {
        while (i < j) {
            // If the sum of nums[i] and nums[j] is greater than the target, move the right pointer left
            if (nums[i] + nums[j] > target) {
                j--;
            } 
            // If the sum is less than the target, move the left pointer right
            else if (nums[i] + nums[j] < target) {
                i++;
            } 
            // If the sum equals the target, we found a valid triplet
            else {
                // Avoid duplicate pairs by skipping elements with the same value
                while (i < j && nums[i] == nums[i + 1]) {
                    i++;
                }
                while (i < j && nums[j] == nums[j - 1]) {
                    j--;
                }
                // Push the triplet into the result
                res.push_back({-target, nums[i], nums[j]});
                i++; // always keep in mind never forget this forgetting this will lead to memory limit exceed
                j--; // always keep in mind never forget this
            }
        }
    }

    // Main function to find all unique triplets that sum to 0
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        // If there are fewer than 3 numbers, no triplets can exist
        if (n < 3) {
            return {};
        }

        res.clear(); // Clears the result every time the function is called to avoid stale data

        // Sort the array to use the two-pointer approach effectively
        sort(nums.begin(), nums.end());

        // Fix one element at a time and use twoSum to find the other two
        for (int i = 0; i < n; i++) {
            // Avoid duplicates for the fixed element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int n1 = nums[i];          // Fixed element
            int target = -n1;          // Target for the two-sum function
            twoSum(i + 1, nums, n - 1, target); // Find the remaining two elements of triplets
        }

        return res;
    }
};
