/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

    Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
    Return k.

*/






#include <stdio.h>

// Function to remove all instances of val in nums
int removeElement(int* nums, int numsSize, int val) {
    int i, j = 0;

    // Traverse the array
    for (i = 0; i < numsSize; i++) {
        // If the current element is not equal to val
        if (nums[i] != val) {
            // Assign nums[i] to nums[j] and increment j
            nums[j] = nums[i];
            j++;
        }
    }

    // Return the new length of the array
    return j;
}

// Helper function to print the array
void printArray(int* nums, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {0,1,2,2,3,0,4,2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int val = 2;

    printf("Original array: ");
    printArray(nums, numsSize);

    int newSize = removeElement(nums, numsSize, val);

    printf("Array after removing %d: ", val);
    printArray(nums, newSize);

    printf("New size: %d\n", newSize);

    return 0;
}
