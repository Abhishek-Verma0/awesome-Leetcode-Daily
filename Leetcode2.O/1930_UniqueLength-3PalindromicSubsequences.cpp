/***
 * 1930. Unique Length-3 Palindromic Subsequences
Solved
Medium
Topics
Companies
Hint

Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

    For example, "ace" is a subsequence of "abcde".

 

Example 1:

Input: s = "aabca"
Output: 3
Explanation: The 3 palindromic subsequences of length 3 are:
- "aba" (subsequence of "aabca")
- "aaa" (subsequence of "aabca")
- "aca" (subsequence of "aabca")

Example 2:

Input: s = "adc"
Output: 0
Explanation: There are no palindromic subsequences of length 3 in "adc".

Example 3:

Input: s = "bbcbaba"
Output: 4
Explanation: The 4 palindromic subsequences of length 3 are:
- "bbb" (subsequence of "bbcbaba")
- "bcb" (subsequence of "bbcbaba")
- "bab" (subsequence of "bbcbaba")
- "aba" (subsequence of "bbcbaba")

 

Constraints:

    3 <= s.length <= 105
    s consists of only lowercase English letters.


 */



class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length(); // Length of the input string
        unordered_set<char> unique_letters; // To store all unique characters in the string

        // Step 1: Collect all unique letters in the string
        for (char &ch : s) {
            unique_letters.insert(ch);
        }

        int result = 0; // To store the count of distinct palindromic subsequences

        // Step 2: Iterate over each unique letter
        for (char letter : unique_letters) {
            int first_idx = -1; // First occurrence index of the current letter
            int last_idx = -1;  // Last occurrence index of the current letter

            // Find the first and last occurrence of the current letter in the string
            for (int i = 0; i < n; i++) {
                if (s[i] == letter) {
                    if (first_idx == -1) {
                        first_idx = i; // Set the first index
                    }
                    last_idx = i; // Update the last index
                }
            }

            // If the letter appears at least twice, process the middle substring
            unordered_set<char> st; // To store unique middle characters
            for (int middle = first_idx + 1; middle <= last_idx - 1; middle++) {
                st.insert(s[middle]); // Collect all unique characters between first and last occurrence
            }

            // Add the count of unique middle characters to the result
            result += st.size();
        }

        return result; // Return the total count of distinct palindromic subsequences
    }
};
