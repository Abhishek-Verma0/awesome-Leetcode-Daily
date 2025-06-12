class Solution {
public:
   
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();        // Get the number of elements in the input vector
        int diff = INT_MIN;          // Initialize the maximum difference with the smallest possible integer

        // Loop through the array from the second element to the last
        for (int i = 1; i < n; i++) {
            // Calculate the absolute difference between the current element and the previous one
            // Update 'diff' if this difference is greater than the current maximum
            if (abs(nums[i - 1] - nums[i]) > diff) {
                diff = abs(nums[i - 1] - nums[i]);
            }
        }

        // Handle the circular condition: compare the last and first elements
        if (abs(nums[0] - nums[n - 1]) > diff) {
            diff = abs(nums[0] - nums[n - 1]);
        }

        // Return the maximum absolute difference found
        return diff;
    }
};
