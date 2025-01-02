/***2559. Count Vowel Strings in Ranges
Solved
Medium
Topics
Companies
Hint

You are given a 0-indexed array of strings words and a 2D array of integers queries.

Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.

Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]
Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
The answer to the query [0,2] is 2 (strings "aba" and "ece").
to query [1,4] is 3 (strings "ece", "aa", "e").
to query [1,1] is 0.
We return [2,3,0].

Example 2:

Input: words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
Output: [3,2,1]
Explanation: Every string satisfies the conditions, so we return [3,2,1].

 

Constraints:

    1 <= words.length <= 105
    1 <= words[i].length <= 40
    words[i] consists only of lowercase English letters.
    sum(words[i].length) <= 3 * 105
    1 <= queries.length <= 105
    0 <= li <= ri < words.length

 */


class Solution {
public:
    // Function to check if a character is a vowel
    bool isVowel(char ch) {
        // Returns true if the character is a vowel, else false
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        } else {
            return false;
        }
    }

    // Main function to process the words and queries
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int count = 0;        // To store the cumulative count of words starting and ending with vowels
        
        unordered_map<int,int> mp;  // Map to store the count of valid words at each index

        int n = words.size();  // Get the number of words

        // Iterate through each word
        for (int i = 0; i < n; i++) {
            // Check if the first and last characters of the word are vowels
            if (isVowel(words[i][0]) && isVowel(words[i][words[i].size() - 1])) {
                count++;  // If they are vowels, increment the count
                mp[i] = count;  // Store the cumulative count in the map
            } else {
                mp[i] = count;  // Otherwise, store the same count (no increment)
            }
        }

        vector<int> res;  // To store the results for each query

        // Iterate through each query
        for (int i = 0; i < queries.size(); i++) {
            int st = queries[i][0];  // Starting index of the query (1-based index)
            int lt = queries[i][1];  // Ending index of the query (1-based index)

            // Calculate the sum of valid words between indices st and lt
            int sum = mp[lt] - mp[st - 1];

            // Push the result into the result vector
            res.push_back(sum);
        }

        // Return the final results
        return res;
    }
};
