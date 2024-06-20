/*Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

 

Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.

Example 2:

Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.

Example 3:

Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.

 

Constraints:

    1 <= nums.length <= 104
    -231 <= nums[i] <= 231 - 1
*/




#include <stdio.h>
#include <limits.h>


// Function to find the third maximum number
int thirdMax(int* nums, int n) {
    // Initialize the three maximum pairs (value, is_present)
    int fm_val = INT_MIN, fm_present = 0;
    int sm_val = INT_MIN, sm_present = 0;
    int tm_val = INT_MIN, tm_present = 0;

    for (int i = 0; i < n; i++) {
        // Update first maximum
        if (nums[i] > fm_val || (nums[i] == INT_MIN && !fm_present)) {
            if (sm_present) {
                tm_val = sm_val;
                tm_present = 1;
            }
            if (fm_present) {
                sm_val = fm_val;
                sm_present = 1;
            }
            fm_val = nums[i];
            fm_present = 1;
        }

        // Skip if it matches the current first maximum
        if (fm_val == nums[i]) {
            continue;
        }

        // Update second maximum
        if (nums[i] > sm_val || (nums[i] == INT_MIN && !sm_present)) {
            if (sm_present) {
                tm_val = sm_val;
                tm_present = 1;
            }
            sm_val = nums[i];
            sm_present = 1;
        }

        // Skip if it matches the current second maximum
        if (sm_val == nums[i]) {
            continue;
        }

        // Update third maximum
        if (nums[i] > tm_val || (nums[i] == INT_MIN && !tm_present)) {
            tm_val = nums[i];
            tm_present = 1;
        }
    }

    // If third maximum is not found, return the first maximum
    if (!tm_present) {
        return fm_val;
    }

    // Return the third maximum number
    return tm_val;
}

int main() {
    int nums[] = {3, 2, 1, 5, 6, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = thirdMax(nums, n);
    printf("The third maximum number is: %d\n", result);

    return 0;
}
