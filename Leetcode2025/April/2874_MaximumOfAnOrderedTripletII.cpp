


class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0, imax = 0, hmax = 0;
        for (int k = 0; k < n; k++) {
            res = max(res, hmax * nums[k]);
            hmax = max(hmax, imax - nums[k]);
            imax = max(imax, static_cast<long long>(nums[k]));
        }
        return res;
    }
};