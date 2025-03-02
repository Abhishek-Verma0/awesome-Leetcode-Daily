/**
 * T.C -- O(n+m)
 * S.C -- O(m)
 */


class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>>res;
        int n1= nums1.size();
        int n2= nums2.size();
        vector<int> notMatch(n2,0);
        int j1=0;
        for(int i=0;i<n1;i++){
        bool ins=true;
            for(int j=0;j<n2;j++){
                    j1=j;
                if(nums1[i][0]==nums2[j][0]){
                    int sum= nums1[i][1] + nums2[j][1];
                    res.push_back({nums1[i][0],sum});
                    notMatch[j]=1;
                    ins= false;
                    break;
                }
                
            }
            if(ins){
                res.push_back({nums1[i][0],nums1[i][1]});
                
            }
        }

        for(int i=0;i<n2;i++){
            if(notMatch[i]==0){
                res.push_back({nums2[i][0],nums2[i][1]});
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};