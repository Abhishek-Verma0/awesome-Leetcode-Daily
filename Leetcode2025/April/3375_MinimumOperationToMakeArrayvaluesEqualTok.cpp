


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> ops;  // To store unique values greater than k

        for (int x : nums) {
            if (x < k) {
                // If any number is less than k, it's impossible to reach k
                return -1;
            } else if (x > k) {
                // Only track values greater than k (these need to be reduced)
                ops.insert(x);
            }
        }

        // The number of unique values > k corresponds to the minimum operations
        return ops.size();
    }
};
