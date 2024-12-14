
/****2762. Continuous Subarrays
Solved
Medium
Topics
Companies
Hint

You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:

    Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.

Return the total number of continuous subarrays.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [5,4,2,4]
Output: 8
Explanation: 
Continuous subarray of size 1: [5], [4], [2], [4].
Continuous subarray of size 2: [5,4], [4,2], [2,4].
Continuous subarray of size 3: [4,2,4].
Thereare no subarrys of size 4.
Total continuous subarrays = 4 + 3 + 1 = 8.
It can be shown that there are no more continuous subarrays.

 

Example 2:

Input: nums = [1,2,3]
Output: 6
Explanation: 
Continuous subarray of size 1: [1], [2], [3].
Continuous subarray of size 2: [1,2], [2,3].
Continuous subarray of size 3: [1,2,3].
Total continuous subarrays = 3 + 2 + 1 = 6.

 

Constraints:

    1 <= nums.length <= 105
    1 <= nums[i] <= 109

 */



class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        // Map to maintain sorted frequency map of current window
        map<int, int> freq;
        int left = 0, right = 0;
        int n = nums.size();
        long long count = 0;  // Total count of valid subarrays

        while (right < n) {
            // Add current element to frequency map
            freq[nums[right]]++;

            // While window violates the condition |nums[i] - nums[j]| ≤ 2
            // Shrink window from left
            while (freq.rbegin()->first - freq.begin()->first > 2) {
                // Remove leftmost element from frequency map
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }

            // Add count of all valid subarrays ending at right
            count += right - left + 1;
            right++;
        }

        return count;
    }
};