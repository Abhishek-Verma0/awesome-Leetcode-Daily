/*
Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

 

Example 1:

Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:

Input: c = 3
Output: false

 

Constraints:

    0 <= c <= 231 - 1


*/




bool judgeSquareSum(int c) {
    // Initialize two pointers
    long left = 0;
    long right = (long)sqrt(c);
    
    // Use two pointers to find if there exist a and b such that a^2 + b^2 = c
    while (left <= right) {
        long sumOfSquares = left * left + right * right;
        if (sumOfSquares == c) {
            return true;
        } else if (sumOfSquares < c) {
            left++;
        } else {
            right--;
        }
    }
    
    return false;
}
