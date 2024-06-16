#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int minIncrementForUnique(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    // Sort the array first
    qsort(nums, numsSize, sizeof(int), compare);

    int count = 0;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] <= nums[i - 1]) {
            int increment = nums[i - 1] - nums[i] + 1;
            nums[i] += increment;
            count += increment;
        }
    }

    return count;
}

int main() {
    int nums[] = {3, 2, 1, 2, 1, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = minIncrementForUnique(nums, numsSize);
    printf("Minimum increments needed: %d\n", result);
    return 0;
}
