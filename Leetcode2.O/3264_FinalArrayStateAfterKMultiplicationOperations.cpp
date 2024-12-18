/***3264. Final Array State After K Multiplication Operations I
Solved
Easy
Topics
Companies
Hint

You are given an integer array nums, an integer k, and an integer multiplier.

You need to perform k operations on nums. In each operation:

    Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
    Replace the selected minimum value x with x * multiplier.

Return an integer array denoting the final state of nums after performing all k operations.

 

Example 1:

Input: nums = [2,1,3,5,6], k = 5, multiplier = 2

Output: [8,4,6,5,6]

Explanation:
Operation	Result
After operation 1	[2, 2, 3, 5, 6]
After operation 2	[4, 2, 3, 5, 6]
After operation 3	[4, 4, 3, 5, 6]
After operation 4	[4, 4, 6, 5, 6]
After operation 5	[8, 4, 6, 5, 6]

Example 2:

Input: nums = [1,2], k = 3, multiplier = 4

Output: [16,8]

Explanation:
Operation	Result
After operation 1	[4, 2]
After operation 2	[4, 8]
After operation 3	[16, 8]

 

Constraints:

    1 <= nums.length <= 100
    1 <= nums[i] <= 100
    1 <= k <= 10
    1 <= multiplier <= 5

 */




class Solution {
public:
    int findMinIndex(vector<int>& nums) {
    int size=nums.size();

    int minIndex = 0; // Assume the first element is the smallest
    for (int i = 1; i < size; i++) {
        if (nums[i] < nums[minIndex]) {
            minIndex = i; // Update minIndex if a smaller element is found
        }
    }
    return minIndex; // Return the index of the minimum element
}
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i=0;i<k;i++){
            int ind=findMinIndex(nums);
            unsigned int mi=nums[ind]*multiplier;
            nums[ind]=mi;
        }
        return nums;
    }
};