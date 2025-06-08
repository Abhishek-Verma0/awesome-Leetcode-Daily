class Solution {
public:
    // This function generates numbers from 1 to n in lexicographical (dictionary) order
    vector<int> lexicalOrder(int n) {
        vector<int> res; // Vector to store the result

        // Start DFS from 1 to 9, because numbers can't start with 0
        for (int i = 1; i <= 9; i++) {
            dfs(i, n, res); // Perform depth-first search starting from i
        }

        return res; // Return the final list
    }
    
    // Helper function to perform depth-first search
    void dfs(int curr, int n, vector<int>& res) {
        // Base case: If current number exceeds n, we stop
        if (curr > n) return;

        // Add the current number to the result list
        res.push_back(curr);

        // Try appending digits 0 to 9 to the current number
        for (int i = 0; i <= 9; i++) {
            // Generate the next number
            int next = curr * 10 + i;

            // If the next number is greater than n, we stop this branch of recursion
            if (next > n) return;

            // Recursively call dfs on the next number
            dfs(next, n, res);
        }
    }
};
