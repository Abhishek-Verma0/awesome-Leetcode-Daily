class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int count = 0; // Keeps track of the total length of palindrome
        unordered_map<string, int> mp; // Stores frequency of each word

        // Traverse each word in the input list
        for (auto &word : words) {
            string revWord = word;
            swap(revWord[0], revWord[1]); // Reverse the word (e.g., "ab" becomes "ba")

            // If the reverse of current word is already in the map, we can pair them
            if (mp[revWord] > 0) {
                mp[revWord]--; // Use up one occurrence of the reverse word
                count += 4;     // Each valid pair adds 4 characters to the palindrome
            } else {
                mp[word]++; // Otherwise, store the current word for future matching
            }
        }

        // After pairing is done, check if any symmetric word like "gg" is left
        for (auto &it : mp) {
            string wr = it.first;
            int num = it.second;

            // If a word is symmetric (e.g., "aa", "cc") and has a leftover, use it in the center
            if (wr[0] == wr[1] && num > 0) {
                count += 2; // Only one symmetric word can be in the middle
                break;      // So we break after finding one
            }
        }

        return count; // Return the maximum length of palindrome we can make
    }
};
