


// Sliding Windows
class Solution {
public: 
    long long min(int a, int b)
    {
        if (a <=b) return a;
        return b;
    }

    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minI = -1;
        int maxI = -1;
        long long result = 0;
        int checking = -1;
        for (int i = 0; i< nums.size(); i++)
        {
            if (nums[i] < minK || nums[i] > maxK) checking = i;
            if (nums[i] == minK) minI = i;
            if (nums[i] == maxK) maxI = i;
            if (min(minI, maxI) - checking >=0) result += min(minI, maxI) - checking;
        }
        return result; 
    }
};  