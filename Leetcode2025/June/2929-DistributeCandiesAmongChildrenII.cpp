class Solution {
public:
    long long distributeCandies(int n, int limit) {

        // Step 1: Determine how many candies the first child (ch1) can get.
        // We are trying all possible values for ch1 from ch1Min to ch1Max.
        // ch1Min = max(0, n - 2*limit): 
        //   The minimum ch1 can get while ensuring that the remaining two children 
        //   can get at most 'limit' candies each. So we subtract 2*limit from n.
        // ch1Max = min(n, limit): 
        //   The maximum ch1 can get is either all candies (n) or the limit.

        int ch1Min = max(0, n - limit * 2);
        int ch1Max = min(n, limit);

        long long ways = 0; // To store total number of valid distributions

        // Step 2: Try every valid value of candies for the first child (ch1)
        for (int ch1 = ch1Min; ch1 <= ch1Max; ch1++) {
            
            // After giving 'ch1' candies to the first child,
            // we are left with 'N' candies to give to the second and third children
            int N = n - ch1;

            // Step 3: Now we need to find the number of valid (ch2, ch3) pairs such that:
            // - ch2 + ch3 == N
            // - 0 <= ch2 <= limit
            // - 0 <= ch3 <= limit

            // This is a classic bounded integer partition problem

            // The minimum value ch2 can take is max(0, N - limit)
            // because ch3 = N - ch2 must be <= limit
            int minCh2 = max(0, N - limit);

            // The maximum value ch2 can take is min(N, limit)
            // because ch2 must be <= limit and ch3 = N - ch2 must be >= 0
            int maxCh2 = min(N, limit);

            // The number of valid (ch2, ch3) pairs is the count of values ch2 can take
            // i.e., all integers from minCh2 to maxCh2 (inclusive)
            ways += (maxCh2 - minCh2 + 1);
        }

        // Step 4: Return total number of valid (ch1, ch2, ch3) combinations
        return ways;
    }
};
