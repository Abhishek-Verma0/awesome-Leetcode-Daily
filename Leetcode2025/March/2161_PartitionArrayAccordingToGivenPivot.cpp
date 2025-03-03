/***
 * T.C -- O(n);
 * S.C -- O(n)
 */

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>small;
        vector<int> big;
        for( int i : nums){
            if(i < pivot){
                small.push_back(i);
            }
            else if(i>pivot){
                big.push_back(i);
            }
        }
        int a=small.size();
        int b=big.size();
        int n= nums.size() - (a+b);
        for(int i=0;i<n;i++){
            small.push_back(pivot);
        }
        for(int i : big){
            small.push_back(i);
        }
    return small;
       
    }
};