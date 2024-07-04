/*283. Move Zeroes
Solved
Easy
Topics
Companies
Hint

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:

Input: nums = [0]
Output: [0]

 

Constraints:

    1 <= nums.length <= 104
    -231 <= nums[i] <= 231 - 1
*/





#include<stdio.h>
    
void print(int* nums, int numsSize){
    printf("[");
    for(int i = 0; i < numsSize; i++) {
        if (i != 0) {
            printf(",");
        }
        printf("%d", nums[i]);
    }
    printf("]\n");
}
void sort(int*nums, int numsSize){
    if(numsSize==1 && nums[0]==0){
        return print(nums,numsSize);
    }
    else{
        for (int i = 0; i < numsSize; i++)
        {
            for(int j=i+1;j<numsSize;j++){
                if(nums[i]==0){
                    int temp=0;
                    temp=nums[j];
                    nums[j]=nums[i];
                    nums[i]=temp;
                }
            }
        }
        
    }
}

void moveZeroes(int* nums, int numsSize) {
     sort(nums,numsSize);

    print(nums,numsSize);
}

