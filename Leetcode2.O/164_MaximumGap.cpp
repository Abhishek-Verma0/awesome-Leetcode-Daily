/***
 * 164. Maximum Gap
Solved
Medium
Topics
Companies

Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.

 

Example 1:

Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.

Example 2:

Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.

 

Constraints:

    1 <= nums.length <= 10^5
    0 <= nums[i] <= 10^9
 */



class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int gap = 0;
        
        // If the input array is empty or has less than two elements, return 0 since no gap can be formed
        if (nums.size() == 0) {
            return 0;
        }

        // Sort the array in ascending order
        sort(nums.begin(), nums.end());
        
        // Get the size of the sorted array
        int n = nums.size();
        
        // Iterate through the sorted array to find the maximum gap
        for (int i = 0; i < n - 1; i++) {
            // Calculate the difference between consecutive elements
            int sub = nums[i + 1] - nums[i];
            
            // Update the maximum gap if a larger gap is found
            if (sub > gap) {
                gap = sub;
            }
        }
        
        // Return the largest gap found between consecutive elements
        return gap;
    }
};
