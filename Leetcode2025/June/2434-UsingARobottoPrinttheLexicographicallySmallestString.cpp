class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        
        // Create a vector to store the minimum character from the current position to the end
        vector<char> minChToRight(n);
        minChToRight[n - 1] = s[n - 1];

        // Fill the vector by comparing each character with the minimum seen so far from the right
        for (int i = n - 2; i >= 0; i--) {
            minChToRight[i] = min(s[i], minChToRight[i + 1]);
        }

        string t = "";      // This simulates the stack used by the robot
        string paper = "";  // This holds the final result (output string)

        int i = 0;
        while (i < n) {
            // Push the current character onto the stack
            t.push_back(s[i]);

            // Find the smallest character in the remaining part of the string
            char minCh = (i + 1 < n) ? minChToRight[i + 1] : s[i];

            // If the top of the stack is smaller than or equal to the smallest remaining character,
            // pop from the stack and add to the result (paper)
            while (!t.empty() && t.back() <= minCh) {
                paper += t.back();
                t.pop_back();
            }

            i++;
        }

        // After processing all characters, empty the remaining stack into the result
        while (!t.empty()) {
            paper += t.back();
            t.pop_back();
        }

        return paper;
    }
};
