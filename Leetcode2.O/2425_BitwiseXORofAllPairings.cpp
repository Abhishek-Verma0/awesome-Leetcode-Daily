/***Approach 1
 * T.C -- O(m+n)
 * S.C -- O(1)
 */

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); // Size of the first array
        int m = nums2.size(); // Size of the second array
        int res = 0; // Initialize result to 0

        // If the size of nums1 is odd, XOR all elements of nums2
        if (n % 2 != 0) {
            for (int num : nums2) {
                res ^= num; // XOR each element of nums2 with the result
            }
        }

        // If the size of nums2 is odd, XOR all elements of nums1
        if (m % 2 != 0) {
            for (int num : nums1) {
                res ^= num; // XOR each element of nums1 with the result
            }
        }

        return res; // Return the final XOR result
    }
};

/***
 * Approach 2
 *
 * T.C -- O(m+n)
 * S.C -- O(N)
 */


class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); // Size of the first array
        int m = nums2.size(); // Size of the second array
        int res = 0; // Initialize result to 0
        unordered_map<int, int> mp; // Map to store the frequency of elements

        // Step 1: For every element in nums1, increment its frequency in the map by m
        for (int num : nums1) {
            mp[num] += m; // Each element in nums1 will appear m times in the XOR operation
        }

        // Step 2: For every element in nums2, increment its frequency in the map by n
        for (int num : nums2) {
            mp[num] += n; // Each element in nums2 will appear n times in the XOR operation
        }

        // Step 3: Iterate over the map and process the elements
        for (auto it : mp) {
            int num = it.first;   // The number
            int freq = it.second; // Its cumulative frequency

            // If the cumulative frequency is odd, XOR the number into the result
            if (freq % 2 != 0) {
                res ^= num; // XOR operation
            }
        }

        return res; // Return the result
    }
};

