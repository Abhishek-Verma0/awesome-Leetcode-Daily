/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.

Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16

 

Constraints:

    1 <= nums.length <= 50000
    1 <= nums[i] <= 10^5
    1 <= k <= nums.length

*/






#include <stdio.h>
#include <stdlib.h>

// Function to count the number of nice subarrays
int numberOfSubarrays(int* nums, int numsSize, int k) {
    // Create a frequency array to store the number of times a prefix sum occurs
    int* freq = (int*)calloc(numsSize + 1, sizeof(int));
    int count = 0, prefixSum = 0, result = 0;
    
    // Initialize the frequency of prefix sum 0 as 1
    freq[0] = 1;
    
    // Traverse through the array
    for (int i = 0; i < numsSize; i++) {
        // Increment prefix sum if the current number is odd
        if (nums[i] % 2 != 0) {
            prefixSum++;
        }
        
        // If there exists a prefix sum that satisfies the condition
        if (prefixSum >= k) {
            result += freq[prefixSum - k];
        }
        
        // Increment the frequency of the current prefix sum
        freq[prefixSum]++;
    }
    
    // Free the allocated memory
    free(freq);
    
    return result;
}

int main() {
    int nums[] = {1, 1, 2, 1, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;
    
    int result = numberOfSubarrays(nums, numsSize, k);
    printf("Number of nice subarrays: %d\n", result);
    
    return 0;
}
