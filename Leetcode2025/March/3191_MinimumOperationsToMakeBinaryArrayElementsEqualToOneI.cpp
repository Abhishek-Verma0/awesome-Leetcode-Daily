/**
 * T.C ->  O(n)
 * S.C -> O(1)
 */



class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0;
        int sz= nums.size();

        for(int i=0;i<sz-2;i++){
            if(nums[i]==0){ // checks if current bit in array is 0 then proceed further
            //  flips current and very next two elements 
            //  here XOR operation with 1 will give 0 and with 0 it will give 1
                nums[i]^=1;   
                nums[i+1]^=1;
                nums[i+2]^=1;
                count++; //increase the number of count
            }
    }
    //  checking if any zero remains in array
    for(int i : nums){
        if(i==0){
            return -1;
        }
    }
    return count;
    }
};