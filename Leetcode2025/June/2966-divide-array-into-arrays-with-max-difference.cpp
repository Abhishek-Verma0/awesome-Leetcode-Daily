class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        /*  so here I thought that like after sorting array  if 1 and 3rd element diff is 
            smaller or equal to k then whole array will have diff less than or equal to k as 
            sorted if any of of the divided array not follows then clear the res 
        */
        for(int i=0;i<n;i+=3){
            if((nums[i+2]-nums[i])<=k && i<n){
                res.push_back({nums[i],nums[i+1],nums[i+2]});
            }
            else{
                res.clear();
                break;
            }
        }
        return res;
    }
};
