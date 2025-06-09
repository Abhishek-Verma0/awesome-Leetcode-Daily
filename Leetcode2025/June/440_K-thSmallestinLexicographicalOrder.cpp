class Solution {
public:
    int findKthNumber(int n, int k) {
        long curr = 1;
        k -= 1; // Because we start from 1

        while (k > 0) {
            long steps = countSteps(n, curr, curr + 1);
            if (steps <= k) {
                k -= steps;
                curr += 1;
            } else {
                k -= 1;
                curr *= 10;
            }
        }

        return curr;
    }

private:
    long countSteps(long n, long curr, long next) {
        long steps = 0;
        while (curr <= n) {
            steps += min(n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
};
