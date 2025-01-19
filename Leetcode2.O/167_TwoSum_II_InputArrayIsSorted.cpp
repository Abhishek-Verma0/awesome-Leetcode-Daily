
/**
 * T.C - O(n)
 * S.C - O(1)
 */



class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // `n` represents the last index of the array
        int n = numbers.size() - 1;

        // Initialize two pointers, one at the start and the other at the end
        int first = 0;
        int last = n;

        // Continue until the target sum is found
        while (true) {
            int sum = numbers[first] + numbers[last]; // Calculate the current sum

            // If the sum matches the target, return the 1-based indices of the two numbers
            if (sum == target) {
                return {first + 1, last + 1};
            }

            // If the current sum is greater than the target, move the right pointer left
            if (sum > target) {
                last--;
            }
            // If the current sum is less than the target, move the left pointer right
            else if (sum < target) {
                first++;
            }
        }

        // Return an empty vector if no valid pair is found (though this line is unreachable)
        return {};
    }
};
