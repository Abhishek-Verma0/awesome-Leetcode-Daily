class Solution {
public:

    // Helper DFS function to find the lexicographically smallest character
    // in the connected component (equivalence class) of a character
    char dfsFindMinCh(unordered_map<char, vector<char>>& adj, char ch, vector<int>& visited) {
        visited[ch - 'a'] = 1; // Mark current character as visited
        char minCh = ch;       // Initialize min character as current

        // Visit all adjacent (equivalent) characters
        for (char& v : adj[ch]) {
            if (visited[v - 'a'] == 0) {
                // Recursively find the smallest character in this connected component
                minCh = min(minCh, dfsFindMinCh(adj, v, visited));
            }
        }
        return minCh; // Return the smallest character found in the component
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();   // Length of s1 and s2 (both are same)
        int m = baseStr.size(); // Length of base string
        unordered_map<char, vector<char>> adj; // Adjacency list to represent graph

        // Build the undirected graph of equivalence relationships
        for (int i = 0; i < n; i++) {
            char u = s1[i];
            char v = s2[i];
            adj[u].push_back(v); // u is equivalent to v
            adj[v].push_back(u); // v is also equivalent to u
        }

        string res = ""; // Result string

        // For each character in baseStr, find the smallest equivalent character
        for (int i = 0; i < m; i++) {
            char ch = baseStr[i];
            vector<int> visited(26, 0); // Track visited characters (a-z)
            char minCh = dfsFindMinCh(adj, ch, visited); // Find smallest equivalent
            res.push_back(minCh); // Append to result
        }

        return res; // Return final transformed string
    }
};
