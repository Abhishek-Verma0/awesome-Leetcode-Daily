/**
 * T.C -> O(n^2)
 * L.C -> O(n^2)
 */


class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        n*=n;
        unordered_map<int,int>mp;
        for(int i=1;i<=n;i++){
            mp[i]=0;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                mp[grid[i][j]]++;
            }
        }
        vector<int>res(2);
        for(const auto& i : mp){
            if( i.second==0){
                res[1]=i.first;
            }
            else if(i.second>1){
                res[0]=i.first;
            }
        }

         return res;
    }
};