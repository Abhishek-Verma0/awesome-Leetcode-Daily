class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
    //  first check if the sum is even then we can achieve equal subset sum else we can't
        if (sum % 2 != 0) {
            return false;
        }
        int targ = sum / 2;

        
        //  using dp to get the partition is possible or not 
        vector<bool> dp(targ + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int currSum = targ; currSum >= num; --currSum) {
                dp[currSum] = dp[currSum] || dp[currSum - num];
                if (dp[targ])
                    return true;
            }
        }
        return dp[targ];
        return true;
    }
};