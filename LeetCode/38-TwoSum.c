/*1. Two Sum
Solved
Easy
Topics
Companies
Hint

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

 

Constraints:

    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.

 
Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?*/









/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

*returnSize=2;

int *array = malloc(2*sizeof(int) ); 

for (int i=0; i<numsSize;i++)
{
    for( int j=1+i;j<numsSize;j++)
    {
        if(nums[i] + nums[j] == target)
        {
        array[0]=i;
        array[1]=j;
        return array;
        }
    }   
    
}
return -1;

}