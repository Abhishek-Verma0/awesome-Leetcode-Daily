/***
 * 1422. Maximum Score After Splitting a String
Solved
Easy
Topics
Companies
Hint

Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

 

Example 1:

Input: s = "011101"
Output: 5 
Explanation: 
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5 
left = "01" and right = "1101", score = 1 + 3 = 4 
left = "011" and right = "101", score = 1 + 2 = 3 
left = "0111" and right = "01", score = 1 + 1 = 2 
left = "01110" and right = "1", score = 2 + 1 = 3

Example 2:

Input: s = "00111"
Output: 5
Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5

Example 3:

Input: s = "1111"
Output: 3

 

Constraints:

    2 <= s.length <= 500
    The string s consists of characters '0' and '1' only.


 */




class Solution {
public:
    int maxScore(string s) {
        // Variable to store the count of '1's in the right partition
        int rightScore = 0;

        // Variable to store the count of '0's in the left partition
        int leftScore = 0;

        // Variable to store the maximum score found during iteration
        int maxScore = 0;

        // Step 1: Count the total number of '1's in the string
        // Initially, all '1's are considered part of the right partition
        for (char ch : s) {
            if (ch == '1') {
                rightScore++;
            }
        }

        // Step 2: Iterate through the string and compute scores for each split point
        // Stop before the last character to ensure valid splits (non-empty left and right)
        for (int i = 0; i < s.length() - 1; i++) {
            // Increment the left score if the current character is '0'
            if (s[i] == '0') {
                leftScore++;
            }

            // Decrement the right score if the current character is '1'
            if (s[i] == '1') {
                rightScore--;
            }

            // Calculate the score for the current split
            int sum = leftScore + rightScore;

            // Update the maximum score if the current score is higher
            maxScore = max(maxScore, sum);
        }

        // Return the maximum score found
        return maxScore;
    }
};
