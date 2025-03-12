/***
 * T.C -> O(n)
 * S.C -> O(1)
 */

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos=0;
        int neg=0;
        for( int i : nums){
            if(i<0){
                neg++;
            }
            else if(i>0){
                pos++;
            }
        }
        return (pos>neg) ? pos : neg;
    }
};