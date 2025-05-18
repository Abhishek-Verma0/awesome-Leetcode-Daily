class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int i = 0;      // Pointer for the next position to place 0 (red)
        int j = 0;      // Current pointer traversing the array stands for 0 (white)
        int k = n - 1;  // Pointer for the next position to place 2 (blue)

        // Traverse the array while j is within the unsorted region
        while (j <= k) {
            if (nums[j] == 1) {
                // 1 is already in the correct region (middle), move on
                j++;
            }
            else if (nums[j] == 2) {
                // Swap current 2 with the last unsorted value (could be 0,1,2)
                swap(nums[j], nums[k]);
                k--;  // Reduce the blue region
                // Do not increment j here because swapped value needs evaluation
            }
            else { // nums[j] == 0
                // Swap current 0 with the first unsorted red region
                swap(nums[j], nums[i]);
                i++;  // Move red boundary forward
                j++;  // Move to next element
            }
        }
    }
};
