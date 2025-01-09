/**
 * 2185. Counting Words With a Given Prefix
Solved
Easy
Topics
Companies
Hint

You are given an array of strings words and a string pref.

Return the number of strings in words that contain pref as a prefix.

A prefix of a string s is any leading contiguous substring of s.

 

Example 1:

Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".

Example 2:

Input: words = ["leetcode","win","loops","success"], pref = "code"
Output: 0
Explanation: There are no strings that contain "code" as a prefix.

 

Constraints:

    1 <= words.length <= 100
    1 <= words[i].length, pref.length <= 100
    words[i] and pref consist of lowercase English letters.


 */



class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size(); // Get the number of words in the list
        int count = 0;        // Initialize a counter to keep track of matches

        // Iterate through each word in the list
        for (int i = 0; i < n; i++) {
            // If the prefix length is greater than the current word's length,
            // skip this word since the prefix cannot match
            if (pref.size() > words[i].size()) {
                continue;
            }

            // Check if the prefix exists at the start of the word
            // 'find(pref) == 0' ensures the prefix is found at index 0
            if (words[i].find(pref) == 0) {
                count++; // Increment the counter if the prefix matches
            }
        }

        return count; // Return the total count of words with the prefix
    }
};
