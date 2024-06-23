/*1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
Solved
Medium
Topics
Companies
Hint

Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

 

Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.

Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.

Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3

 

Constraints:

    1 <= nums.length <= 105
    1 <= nums[i] <= 109
    0 <= limit <= 109

*/



// sliding window
// time: O(n)
// space: O(1)
int longestSubarray(int* nums, int numsSize, int limit)
{
    int result = 1;
    int left_i = 0;
    int min_i = 0;
    int max_i = 0;

    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] < nums[min_i]) {
            min_i = i;
            if (nums[max_i] - nums[min_i] > limit) {
                max_i = min_i;
                left_i = min_i;
                while (nums[left_i-1] - nums[min_i] <= limit) {
                    left_i--;
                    if (nums[left_i] > nums[max_i]) {
                        max_i = left_i;
                    }
                }
            }
        }
        else if (nums[i] > nums[max_i]) {
            max_i = i;
            if (nums[max_i] - nums[min_i] > limit) {
                min_i = max_i;
                left_i = min_i;
                while (nums[max_i] - nums[left_i-1] <= limit) {
                    left_i--;
                    if (nums[left_i] < nums[min_i]) {
                        min_i = left_i;
                    }
                }
            }
        }
        if (i - left_i >= result) {
            result = i - left_i + 1;
        }
    }

    return result;
}

