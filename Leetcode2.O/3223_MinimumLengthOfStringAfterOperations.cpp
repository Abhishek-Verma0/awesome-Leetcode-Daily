
/***
 * Complexity:
 *  1.  Time complexity: O(N)
 *  2. Space complexity: O(1)
 */


class Solution {
public:
    int minimumLength(string s) {
        int n = s.size(); // Get the length of the input string
        
        // Base case: If the string has fewer than 3 characters, return its length directly
        if (n < 3) {
            return n;
        }

        // Step 1: Use an unordered_map to store the frequency of each character
        unordered_map<char, int> freq; 
        for (char ch : s) { // Iterate through each character in the string
            freq[ch]++; // Increment the frequency of the current character
        }

        int len = 0; // Initialize the variable to calculate the final minimum length

        // Step 2: Iterate through the string again and reduce frequencies
        for (char ch : s) {
            if (freq[ch] >= 3) { // If the frequency of the current character is at least 3
                freq[ch] = freq[ch] - 2; // Reduce its frequency by 2
            }
        }

        // Step 3: Calculate the remaining length based on the updated frequencies
        for (auto &sz : freq) { // Iterate over each key-value pair in the frequency map
            len += sz.second; // Add the remaining frequency of each character to `len`
        }

        return len; // Return the final length  of the strings after the operations 

    }
};
