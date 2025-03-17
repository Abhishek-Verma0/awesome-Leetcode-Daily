
/**
 * T.C -> O(n)
 * S.C -> O(1) 
 */
 

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i+=2){
            if(i<nums.size()){
            sum+=min(nums[i],nums[i+1]);
            }
        }
        return sum;
    }
};