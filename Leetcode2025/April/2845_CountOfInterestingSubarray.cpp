


class Solution {
public:
    static long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        const int n=nums.size();
        vector<int> mp(1, 1);// mp[0]=1 as the same
        mp.reserve(n);
        long long ans=0;
        int prefix=0;
        for(int i=0; i<n; i++){
            prefix+=((nums[i]%modulo)==k);
            if (prefix>=min((int)mp.size(), modulo))// size for mp not enough
                mp.resize(2*prefix);// resize mp with 2*prefix instead of 1 by 1
            if (prefix<k){// when prefix<k, prefix is not seen before
                mp[prefix]++;
                continue;
            }
            ans+=mp[(prefix-k)%modulo];
            mp[prefix%modulo]++;
        }
        return ans;
    }
};