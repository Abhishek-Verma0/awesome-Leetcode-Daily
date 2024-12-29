/***1639. Number of Ways to Form a Target String Given a Dictionary
Solved
Hard
Topics
Companies
Hint

You are given a list of strings of the same length words and a string target.

Your task is to form target using the given words under the following rules:

    target should be formed from left to right.
    To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
    Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
    Repeat the process until you form the string target.

Notice that you can use multiple characters from the same string in words provided the conditions above are met.

Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: words = ["acca","bbbb","caca"], target = "aba"
Output: 6
Explanation: There are 6 ways to form target.
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")

Example 2:

Input: words = ["abba","baab"], target = "bab"
Output: 4
Explanation: There are 4 ways to form target.
"bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
"bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
"bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
"bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")

 

Constraints:

    1 <= words.length <= 1000
    1 <= words[i].length <= 1000
    All strings in words have the same length.
    1 <= target.length <= 1000
    words[i] and target contain only lowercase English letters.

 */






class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int MOD = 1000000007;
        int m = words[0].size(); // Number of columns in words
        int n = target.size();  // Length of the target

        // Step 1: Precompute character frequencies in each column
        vector<vector<int>> freq(m, vector<int>(26, 0));
        for (const string& word : words) {
            for (int i = 0; i < m; ++i) {
                freq[i][word[i] - 'a']++;
            }
        }

        // Step 2: Dynamic Programming
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1; // Base case: 1 way to form an empty target

        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                // Case 1: Skip the current column
                dp[i][j] = dp[i - 1][j];

                // Case 2: Use the current column (only if j > 0)
                if (j > 0) {
                    int charIndex = target[j - 1] - 'a';
                    dp[i][j] = (dp[i][j] + (long long)dp[i - 1][j - 1] * freq[i - 1][charIndex]) % MOD;
                }
            }
        }

        return dp[m][n];
    }
};