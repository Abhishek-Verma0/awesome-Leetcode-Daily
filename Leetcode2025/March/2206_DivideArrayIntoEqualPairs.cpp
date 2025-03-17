

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();  // Get the size of the input array
        unordered_map<int, int> mp;  // Hash map to store frequency of each element
        bool pair = true;  // Boolean flag to track if all elements can be paired

        // Check if the array size is even; if it's odd, pairing is impossible
        if (n % 2 == 0) {
            // Count the occurrences of each number in the array
            for (int i : nums) {
                mp[i]++;
            }

            // Check if every element appears an even number of times
            for (auto& i : mp) {
                if (i.second % 2 != 0) {  // If any element appears an odd number of times
                    pair = false;  // Cannot be paired
                    break;  // Exit loop early as pairing is impossible
                }
            }
        }

        // Return true if all elements can be paired, otherwise return false
        if (pair) {
            return true;
        }
        return false;
    }
};
