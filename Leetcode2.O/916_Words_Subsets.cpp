/**
 * 916. Word Subsets
Solved
Medium
Topics
Companies

You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

    For example, "wrr" is a subset of "warrior" but is not a subset of "world".

A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.

 

Example 1:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]

Example 2:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
Output: ["apple","google","leetcode"]

 

Constraints:

    1 <= words1.length, words2.length <= 104
    1 <= words1[i].length, words2[i].length <= 10
    words1[i] and words2[i] consist only of lowercase English letters.
    All the strings of words1 are unique.


 */


class Solution {
public:
    // Helper function to check if all characters in freq2 are satisfied by temp
    bool isSubset(vector<int>& freq2, vector<int>& temp) {
        for (int i = 0; i < 26; i++) { // Check all 26 letters
            if (temp[i] < freq2[i]) {
                return false; // If temp has fewer of any character, return false
            }
        }
        return true; // Otherwise, it's a valid subset
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result; // Stores the universal words from words1
        vector<int> freq2(26, 0); // Frequency array for max character requirements

        // Step 1: Build the frequency requirement for words2
        for (string &word : words2) {
            vector<int> temp(26, 0); // Temporary frequency array for the current word
            for (char &ch : word) {
                temp[ch - 'a']++; // Count the character's frequency
                freq2[ch - 'a'] = max(freq2[ch - 'a'], temp[ch - 'a']); // Update global max
            }
        }

        // Step 2: Check each word in words1 against the frequency requirement
        for (string &word : words1) {
            vector<int> temp(26, 0); // Frequency array for the current word
            for (char &ch : word) {
                temp[ch - 'a']++; // Count the character's frequency
            }

            // If the word satisfies the subset condition, add it to the result
            if (isSubset(freq2, temp)) {
                result.push_back(word);
            }
        }

        return result; // Return the list of universal words
    }
};
