/***
 * T.C -- O(N)
 * S.C -- O(1)
 */



class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size(); // Get the size of the input array 'derived'
        int Xor = 0; // Initialize a variable to store the cumulative XOR of elements in 'derived'
        
        // Iterate over all elements of the array
        for (int i = 0; i < n; i++) {
            Xor ^= derived[i]; // Perform XOR with the current element
        }

        // If the cumulative XOR equals 1, it is not possible to construct the original array
        if (Xor == 1) {
            return false; // Return false if XOR is 1
        }

        return true; // Return true if XOR is 0
    }
};
