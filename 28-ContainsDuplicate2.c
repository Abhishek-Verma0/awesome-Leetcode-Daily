/*219. Contains Duplicate II
Solved
Easy
Topics
Companies

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false

 

Constraints:

    1 <= nums.length <= 105
    -109 <= nums[i] <= 109
    0 <= k <= 105

*/




struct node {
    int val;
    int index;
};

int md_comparator(const void *v1, const void *v2)
{
    const struct node *p1 = (struct node *)v1;
    const struct node *p2 = (struct node *)v2;
    if (p1->val < p2->val)
        return -1;
    else if (p1->val > p2->val)
        return +1;
    else
        return 0;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    
    struct node dict[numsSize];
    for (int i = 0; i < numsSize; i++) {
            dict[i].val = nums[i];
            dict[i].index = i;
    }
    
    qsort(dict, numsSize, sizeof(struct node), md_comparator);

    for (int i = 1; i < numsSize; i++) {
        if(dict[i-1].val == dict[i].val) {
            if ((dict[i].index - dict[i-1].index) <= k) {
                return true;
            }
        }
    }

return false;
}