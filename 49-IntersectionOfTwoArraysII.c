/*350. Intersection of Two Arrays II
Solved
Easy
Topics
Companies

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.

 

Constraints:

    1 <= nums1.length, nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 1000

 

Follow up:

    What if the given array is already sorted? How would you optimize your algorithm?
    What if nums1's size is small compared to nums2's size? Which algorithm is better?
    What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

*/




 int cmp(const void *a, const void *b)
 {
     return (*(int*)a-*(int*)b);
 }

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){

    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);

    int i=0, j=0, count=0;

    while (i<nums1Size && j<nums2Size)
    {
        if (nums1[i]>nums2[j]) j++;

        else if (nums1[i]<nums2[j]) i++;
        
        else if(nums1[i]==nums2[j])
        {
            nums1[count] = nums1[i];
            count++;
            i++;
            j++;
        }
    }

    *returnSize = count;
    return nums1;
}