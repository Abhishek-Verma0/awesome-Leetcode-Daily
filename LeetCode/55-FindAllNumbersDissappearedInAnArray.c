/*448. Find All Numbers Disappeared in an Array
Solved
Easy
Topics
Companies
Hint

Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:

Input: nums = [1,1]
Output: [2]

 

Constraints:

    n == nums.length
    1 <= n <= 105
    1 <= nums[i] <= n

 

Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
*/






/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    
    int *set = (int*)malloc((numsSize + 1) * sizeof(int));


    for(int i =0; i< numsSize; i++)
    {
        set[i] = 0;
    }

    for(int i =0; i < numsSize; i++)
    {
        set[nums[i]] = 1;
    }

    int *result = (int*)malloc(sizeof(int) *numsSize);    
    int count = 0;
    for(int i = 1; i <= numsSize; i++)
    {
        if(set[i] != 1)
        {
           result[count]  = i;
           count++;         
        }
    }

    *returnSize = count;
    return result;
}