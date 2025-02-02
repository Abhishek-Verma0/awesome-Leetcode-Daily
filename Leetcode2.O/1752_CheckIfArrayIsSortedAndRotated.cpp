/***
 * T.C -- O(N)
 * S.C -- O(1)
 */


class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int max = 0;  // Count of decreasing points

        // Traverse the array
        for(int i = 0; i < n; i++) {
            // If current element is greater than the next (circularly checked)
            if(nums[i] > nums[(i+1) % n]) {
                max++;  // Increase count
            }
        }

        // If there's at most one drop, it's a valid rotation
        return max <= 1;
    }
};
