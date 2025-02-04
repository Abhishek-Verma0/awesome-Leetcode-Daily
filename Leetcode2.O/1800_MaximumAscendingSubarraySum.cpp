/**
 * T.C -- O(n)
 * S.C - O(1)
 */

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        // Initialize variables to store the maximum sum found so far
        int maxSum = 0;
        
        // Start the first ascending subarray sum with the first element
        int currentSum = nums[0];

        // Iterate over the array from the second element
        for(int i = 1; i < nums.size(); i++) {
            // If the current number is greater than the previous one, continue the ascending sequence
            if(nums[i] > nums[i - 1]) {
                currentSum += nums[i]; // Add the number to the ongoing sum
            } 
            else {
                // If the sequence breaks, update maxSum and reset currentSum for the new subarray
                maxSum = max(maxSum, currentSum);
                currentSum = nums[i]; // Start new sequence
            }
        }

        // Compare the last calculated sum with maxSum before returning
        return max(maxSum, currentSum);
    }
};
