class Solution {
public:
    // Define a shorthand name for pair<int, int>
    typedef pair<int, int> p;

    // Custom comparator for the priority_queue
    struct comp {
        // This comparator sorts based on character value in descending order.
        // If characters are the same, then sort by index in ascending order.
        bool operator()(p& p1, p& p2) {
            if (p1.first == p2.first) {
                return p1.second < p2.second; // Smaller index comes later (higher priority)
            }
            return p1.first > p2.first; // Higher character comes first (lower priority)
        }
    };

    string clearStars(string s) {
        int n = s.size();

        // Priority queue to store characters and their indices
        // The top of the queue gives the smallest character (and earliest index in case of tie)
        priority_queue<p, vector<p>, comp> pq;

        // Traverse the string
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                // Push (character, index) into the priority queue
                pq.push({s[i], i});
            } else {
                // When a '*' is found, remove the smallest character seen so far
                int idx = pq.top().second; // Get index of character to remove
                pq.pop();                  // Remove it from the queue
                s[idx] = '*';              // Mark the character as deleted in the original string
            }
        }

        // Build the final string without the removed characters (i.e., without '*')
        string res = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                res.push_back(s[i]); // Add non-deleted characters to result
            }
        }

        return res; // Return the cleaned-up string
    }
};
