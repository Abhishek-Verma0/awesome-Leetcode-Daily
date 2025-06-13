class Solution {
public:
    int n;
    bool isVal(vector<int>&nums,int mid,int p){
        int i=0;
        int count=0;
        while(i<=n-2){
            if(abs(nums[i]-nums[i+1])<=mid){
                count++;
                i+=2;
            }
            else{
                i++;
            }
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums[n-1] -nums[0];
        int res=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isVal(nums,mid,p)){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;

    }
};
