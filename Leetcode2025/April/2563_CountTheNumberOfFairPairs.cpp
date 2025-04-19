

class Solution {
public:
    //  function to return number of fair pairs
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        //  sort the array
        sort(nums.begin(), nums.end());

        // Count pairs with sum ≤ upper
        //         minus pairs with sum < lower ( ≤ lower - 1)
        return countPairs(nums, upper) - countPairs(nums, lower - 1);
    }

private:
    // Helper function to count number of pairs (i < j) where nums[i] + nums[j] ≤ bound
    long long countPairs(vector<int>& nums, int bound) {
        long long count = 0;
        int i = 0, j = nums.size() - 1;

        // Two-pointer technique
        while (i < j) {
            if (nums[i] + nums[j] <= bound) {
                // All pairs from i to j are valid: (i, j), (i, j-1), ..., (i, i+1)
                count += (j - i);
                i++; // Move to next i
            } else {
                j--; // Reduce sum by moving j left
            }
        }
        return count;
    }
};
