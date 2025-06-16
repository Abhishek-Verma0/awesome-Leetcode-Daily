class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size(); // Store the size of the input array
        int dif = -1; // Initialize the maximum difference to -1 (default if no
                      // valid difference is found)
        int min = nums[0]; // Initialize the minimum value to the first element
                           // of the array

        // Traverse the array from the second element
        for (int i = 1; i < n; i++) {
            // If the current number is smaller than the current minimum, update
            // the minimum
            if (nums[i] > min) {
                // Otherwise, calculate the difference between current number
                // and minimum so far
                int temp = nums[i] - min;
                // Update the maximum difference if this difference is larger
                dif = max(temp, dif);
            } else {
                min = nums[i];
            }
        }

        // return  maximum difference found, or -1 if no valid increasing
        // pair exists
        return dif;
    }
};
