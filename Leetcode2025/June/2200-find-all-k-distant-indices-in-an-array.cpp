class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
            int n= nums.size();
            
            vector<int>res;
            for(int i=0;i<n;i++){
                if(nums[i]==key){
                    int start=max(0,i-k);
                    int end=min(i+k,n-1);
                    if(res.size()>0 && res.back()>=start){
                        start=res.back()+1;
                    }
                    for(int j=start;j<=end;j++){
                        res.push_back(j);
                    }
                }
            }
            return res;
    }
};
