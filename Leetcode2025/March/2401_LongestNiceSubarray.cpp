/***
 * T.C -> O(n)
 * S.C -> O(1)
 */

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = 0, maxLen = 0;
        int usedBits = 0;  // Bitmask to track used bits

        for (int end = 0; end < n; end++) {
            // If adding nums[end] causes overlap, shrink the window
            while ((usedBits & nums[end]) != 0) {
                usedBits ^= nums[start];  // Remove nums[start] bits
                start++;
            }

            // Add nums[end] bits to the bitmask
            usedBits |= nums[end];

            // Update maximum length
            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};
