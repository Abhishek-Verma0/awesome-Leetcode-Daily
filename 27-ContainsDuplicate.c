/*217. Contains Duplicate
Solved
Easy
Topics
Companies

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]
Output: true

Example 2:

Input: nums = [1,2,3,4]
Output: false

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

 

Constraints:

    1 <= nums.length <= 105
    -109 <= nums[i] <= 109

*/



#include <stdio.h>
#include <stdbool.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to check for duplicates
bool containsDuplicate(int* nums, int numsSize) {
    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Check for duplicates
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 2}; // Example array with duplicates
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    if (containsDuplicate(nums, numsSize)) {
        printf("The array contains duplicates.\n");
    } else {
        printf("The array does not contain duplicates.\n");
    }
    
    return 0;
}
