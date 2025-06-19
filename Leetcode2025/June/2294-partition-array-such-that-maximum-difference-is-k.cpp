class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt=0;
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        while(j<n){
            if((nums[j]-nums[i])<=k){
                j++;
            }
            else{
                cnt++;
                i=j;
                j++;
            }
        }
        cnt++; // for last group
        return cnt;
    }
};
