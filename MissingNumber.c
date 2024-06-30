/*268. Missing Number
Solved
Easy
Topics
Companies

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.

 */



int missingNumber(int* nums, int numsSize) {
    int fo = -1; // Initialize fo to -1 (assuming missing number can be 0 or positive)

    // Check against all numbers from 0 to numsSize
    for(int j = 0; j <= numsSize; j++) {
        int found = 0; // Flag to check if j is found in nums
        
        // Check if j exists in nums array
        for(int i = 0; i < numsSize; i++) {
            if(nums[i] == j) {
                found = 1; // Mark j as found in nums
                break; // No need to continue checking
            }
        }
        
        // If j is not found in nums, it's the missing number
        if(!found) {
            fo = j;
            break; // No need to check further
        }
    }
    
    return fo;
}
