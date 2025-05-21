class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        
        // Step 1: Initialize difference array
        vector<int> dif(n, 0);

        // Step 2: Apply each query as a range increment
        for (int i = 0; i < m; i++) {
            int st = queries[i][0];
            int ed = queries[i][1];
            
            dif[st] += 1;
            if (ed + 1 < n) {
                dif[ed + 1] -= 1;
            }
        }

        // Step 3: Build cumulative (prefix sum) array
        vector<int> cum(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += dif[i];
            cum[i] = sum;
        }

        //  Check if each index i has at least nums[i] increments
        for (int i = 0; i < n; i++) {
            if (cum[i] < nums[i]) {
                return false; // Not enough increments to zero nums[i]
            }
        }

        return true;
    }
};
