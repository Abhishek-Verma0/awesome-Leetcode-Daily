


class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> mp, mp1;  // `mp` stores frequency in the entire array, `mp1` stores frequency in left partition
        int n = nums.size();

        // Step 1: Count the frequency of each element in the entire array
        for (int num : nums) {
            mp[num]++;
        }

        // Step 2: Iterate through the array to find the valid split index
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            mp[num]--; // Remove current element from the right partition
            mp1[num]++; // Add current element to the left partition

            // Step 3: Check if the current element is dominant in both partitions
            if (mp1[num] * 2 > i + 1 && mp[num] * 2 > n - i - 1) {
                return i; // Return the first valid split index
            }
        }

        return -1; // Return -1 if no valid index is found
    }
};