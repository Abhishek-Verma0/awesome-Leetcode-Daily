/**1408. String Matching in an Array
Solved
Easy
Topics
Companies
Hint

Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.

A substring is a contiguous sequence of characters within a string

 

Example 1:

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.

Example 2:

Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".

Example 3:

Input: words = ["blue","green","bu"]
Output: []
Explanation: No string of words is substring of another string.

 

Constraints:

    1 <= words.length <= 100
    1 <= words[i].length <= 30
    words[i] contains only lowercase English letters.
    All the strings of words are unique.

 */


class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size(); // Get the number of words in the list
        vector<string> res;   // Resultant vector to store matching substrings

        // Outer loop iterates over each word in the list
        for (int i = 0; i < n; i++) {
            // Inner loop checks the current word (words[i]) against all other words
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue; // Skip comparison if both indices are the same
                }

                // Check if words[i] is a substring of words[j]
                if (words[j].find(words[i]) != string::npos) {
                    res.push_back(words[i]); // Add words[i] to result
                    break; // Break to avoid adding duplicates of words[i]
                }
            }
        }

        return res; // Return the list of matching substrings
    }
};
