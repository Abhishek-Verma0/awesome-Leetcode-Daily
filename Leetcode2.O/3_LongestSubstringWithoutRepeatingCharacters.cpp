/***
 * 3. Longest Substring Without Repeating Characters
Solved
Medium
Topics
Companies
Hint

Given a string s, find the length of the longest
substring
without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

 

Constraints:

    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.


 */





class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(); // stores the length of string
        int i = 0, j = 0;   // initialzing the two pointer start and end
                            // respectively initially both at same index
        int maxLen = 0;     // to store the max len of substring

        unordered_set<char>
            ch; // to store the character of the substring and avoid duplicates

        while (j < n) {
            if (ch.find(s[j]) == ch.end()) { // it tell value was not found in map if this condition is true
                ch.insert(s[j]);             // inserts the char into the map
                maxLen = max(maxLen,j - i + 1); // find maximum length and store it in the variable
                j++;        // move forward the end pointer
            }
            else{
                ch.erase(s[i]); // delete the very first char
                i++; // move forward start pointer
            }
        }
        return maxLen;
    }
};