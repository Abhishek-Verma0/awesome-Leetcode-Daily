class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;

        // Step 1: Count frequencies of each number
        for (int num : nums) {
            frequencyMap[num]++;
        }

        int maxLength = 0;

        // Step 2: Check all possible (num, num+1) pairs
        for (auto& [num, count] : frequencyMap) {
            if (frequencyMap.count(num + 1)) {
                int currentLength = count + frequencyMap[num + 1];
                maxLength = max(maxLength, currentLength);
            }
        }

        return maxLength;
    }
};
