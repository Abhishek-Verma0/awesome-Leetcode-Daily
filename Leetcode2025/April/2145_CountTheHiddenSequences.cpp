



class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long min_sum = 0, max_sum = 0, curr = 0;

        for (int diff : differences) {
            curr += diff;
            min_sum = min(min_sum, curr);
            max_sum = max(max_sum, curr);
        }

        long long start_min = lower - min_sum;
        long long start_max = upper - max_sum;

        long long valid = start_max - start_min + 1;
        return valid >= 0 ? valid : 0;
    }
};
