/*Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

 

Example 1:

Input: nums = [1,2,3]
Output: 6

Example 2:

Input: nums = [1,2,3,4]
Output: 24

Example 3:

Input: nums = [-1,-2,-3]
Output: -6
*/




#include <stdio.h>
#include <limits.h>

int maximumProduct(int* nums, int numsSize) {
    // Initialize min1, min2, max1, max2, max3
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max3 = INT_MIN;

    // Traverse the array
    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];

        // Check for maximum
        if (val >= max1) {
            max3 = max2;
            max2 = max1;
            max1 = val;
        } else if (val >= max2) {
            max3 = max2;
            max2 = val;
        } else if (val >= max3) {
            max3 = val;
        }

        // Check for minimum
        if (val <= min1) {
            min2 = min1;
            min1 = val;
        } else if (val <= min2) {
            min2 = val;
        }
    }

    // Calculate maximum product
    int max_product1 = min1 * min2 * max1;
    int max_product2 = max1 * max2 * max3;
    return (max_product1 > max_product2) ? max_product1 : max_product2;
}