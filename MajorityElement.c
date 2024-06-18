/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

*/


#include <stdio.h>

// Function to find the majority element using Boyer-Moore Voting Algorithm
int majorityElement(int* nums, int numsSize) {
    int count = 0;
    int candidate = 0;

    // Phase 1: Find a candidate
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        count += (nums[i] == candidate) ? 1 : -1;
    }

    // Phase 2: Validate the candidate (optional step if we are guaranteed that a majority element always exists)
    count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate) {
            count++;
        }
    }

    if (count > numsSize / 2) {
        return candidate;
    } else {
        // This case shouldn't happen if the input guarantees a majority element exists
        return -1; // Placeholder, adjust as necessary for your use case
    }
}

int main() {
    int nums[] = {2, 2, 1, 1, 1, 2, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = majorityElement(nums, numsSize);
    printf("The majority element is: %d\n", result);
    return 0;
}
