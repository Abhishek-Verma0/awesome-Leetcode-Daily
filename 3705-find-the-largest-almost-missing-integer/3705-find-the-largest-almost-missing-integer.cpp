class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int i : nums) {
            mp[i]++;
        }

        int ans = -1;
        if (k == 1) {
            for (int i : nums) {
                if (mp[i] == 1)
                    ans = max(ans, i);
            }
            return ans;
        }
        int n = nums.size();
        if (k > n)
            return -1;
        if (k == n)
            return *max_element(nums.begin(), nums.end());
        int first = nums[0];
        int lst = nums[n - 1];
        if (mp[first] > 1 && mp[lst] > 1)
            return -1;
        if (mp[first] > 1 && mp[lst] == 1)
            return lst;
        if (mp[first] == 1 && mp[lst] > 1)
            return first;
        return max(first, lst);
    }
};