/***
 * T.C --> O(N∗Sqrt(N))

 * S.C --> O(1)
 */


class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;

        // Handle special case for prime number 2
        if (left <= 2 && right >= 2) {
            primes.push_back(2);
        }

        // Check odd numbers only (all even numbers > 2 are non-prime)
        for (int i = max(3, left); i <= right; i += (i == 3 ? 2 : 1)) {
            bool isPrime = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                primes.push_back(i);
            }
        }

        if (primes.size() < 2) {
            return {-1, -1};  // No valid pair found
        }

        // Find closest prime pair
        int minDiff = INT_MAX;
        vector<int> res(2, -1);
        for (int i = 0; i < primes.size() - 1; i++) {
            int diff = primes[i + 1] - primes[i];
            if (diff < minDiff) {
                minDiff = diff;
                res[0] = primes[i];
                res[1] = primes[i + 1];
            }
        }

        return res;
    }
};