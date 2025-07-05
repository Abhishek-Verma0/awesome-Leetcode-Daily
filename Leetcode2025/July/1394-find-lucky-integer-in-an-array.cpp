class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>freq;
        for(int num : arr){
            freq[num]++;
        }
        int luck=-1;
        for(auto& [key,value] : freq){
            if(key==value){
                luck=max(luck,key);
            }
        }
        return luck;
    }
};
