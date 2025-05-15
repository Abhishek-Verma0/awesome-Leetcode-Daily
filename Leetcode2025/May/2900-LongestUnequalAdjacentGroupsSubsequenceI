class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        // This vector will store the resulting subsequence
        vector<string> st;

        // Loop through each word and its corresponding group
        for (int i = 0; i < words.size(); i++) {
            // Include the first word unconditionally
            // OR include the word only if its group is different from the previous one
            if (i == 0 || groups[i] != groups[i - 1]) {
                st.push_back(words[i]);
            }
        }

        // Return the longest valid subsequence of words
        return st;
    }
};
