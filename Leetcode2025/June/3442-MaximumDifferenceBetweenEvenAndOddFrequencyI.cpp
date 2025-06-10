class Solution {
public:
    int maxDifference(string s) {
        // Create a hash map to store the frequency of each character in the string
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;  // Increment frequency of current character
        }

        // Initialize variables to store max odd frequency and min even frequency
        int od = INT_MIN;  // Maximum among odd frequencies
        int ev = INT_MAX;  // Minimum among even frequencies

        // Iterate through the frequency map
        for (auto &it : freq) {
            // If the frequency is even
            if (it.second % 2 == 0) {
                // Update ev if current frequency is smaller than the current min even
                if (it.second < ev) {
                    ev = it.second;
                }
            }
            // If the frequency is odd
            else {
                // Update od if current frequency is larger than the current max odd
                if (it.second > od) {
                    od = it.second;
                }
            }
        }

        // Return the difference between the max odd and min even frequencies
        
        return od - ev;
    }
};
