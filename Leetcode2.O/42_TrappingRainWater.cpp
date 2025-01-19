/***
 * T.C -- O(n)
 * S.C -- O(n)
 */



class Solution {
public:
    // Function to calculate the maximum height to the left of each index
    vector<int> left_maxArr(vector<int>& height, int n) {
        vector<int> l_max(n); // Array to store the left maximum heights
        l_max[0] = height[0]; // First element is its own maximum
        for (int i = 1; i < n; i++) {
            l_max[i] = max(l_max[i - 1], height[i]); // Take the maximum of the current and previous maximum
        }
        return l_max; // Return the left maximum array
    }

    // Function to calculate the maximum height to the right of each index
    vector<int> right_maxArr(vector<int>& height, int n) {
        vector<int> r_max(n); // Array to store the right maximum heights
        r_max[n - 1] = height[n - 1]; // Last element is its own maximum
        for (int i = n - 2; i >= 0; i--) {
            r_max[i] = max(r_max[i + 1], height[i]); // Take the maximum of the current and next maximum
        }
        return r_max; // Return the right maximum array
    }

    // Function to calculate the total trapped water
    int trap(vector<int>& height) {
        int n = height.size(); // Length of the height array
        // Get the left and right maximum arrays
        vector<int> left_max = left_maxArr(height, n);
        vector<int> right_max = right_maxArr(height, n);

        int sum = 0; // Variable to store the total trapped water
        // Loop through each index and calculate the trapped water at that index
        for (int i = 0; i < n; i++) {
            // Water trapped is the minimum of left_max and right_max minus the current height
            int h = min(left_max[i], right_max[i]) - height[i];
            sum += h; // Add the trapped water at the current index to the total
        }

        return sum; // Return the total trapped water
    }
};
