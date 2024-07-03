/*66. Plus One
Solved
Easy
Topics
Companies

You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].

 

Constraints:

    1 <= digits.length <= 100
    0 <= digits[i] <= 9
    digits does not contain any leading 0's.

*/






/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
        // Initialize carry
    int carry = 1;

    // Traverse the array from the last digit
    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;

        // If there is no carry, break early
        if (carry == 0) {
            *returnSize = digitsSize;
            int* result = (int*)malloc(digitsSize * sizeof(int));
            for (int j = 0; j < digitsSize; j++) {
                result[j] = digits[j];
            }
            return result;
        }
    }

    // If there is still a carry, we need an extra digit
    if (carry != 0) {
        *returnSize = digitsSize + 1;
        int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
        result[0] = carry;  // The carry becomes the new leading digit
        for (int i = 1; i <= digitsSize; i++) {
            result[i] = digits[i - 1];
        }
        return result;
    }

    // If we finished without a carry, return the original size array
    *returnSize = digitsSize;
    int* result = (int*)malloc(digitsSize * sizeof(int));
    for (int i = 0; i < digitsSize; i++) {
        result[i] = digits[i];
    }
    return result;
}

// For debugging purposes
void printArray(int* array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i != 0) printf(",");
        printf("%d", array[i]);
    }
    printf("]\n");
}


