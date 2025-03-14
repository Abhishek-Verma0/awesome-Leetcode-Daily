/**
 * T.C ->   O(log(n))
 * S.C ->   O(1)
 * 
 */


class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        // Find the maximum number of candies in any pile
        int maxCandiesInPile = 0;
        for (int i = 0; i < candies.size(); i++) {
            maxCandiesInPile = max(maxCandiesInPile, candies[i]);
        }

        // Set the initial search range for binary search
        int left = 0;
        int right = maxCandiesInPile;

        // using the binary search to get the max number of candies that a single child can get 
        
        while (left < right) {
            // calculating the middle value of the given range 
            int middle = (left + right + 1) / 2;

            // Check if it's possible to allocate candies so that each child
            // gets 'middle' candies
            if (canAllocateCandies(candies, k, middle)) {
                // If possible, move to the upper half to search for a larger
                // number
                left = middle;
            } else {
                // Otherwise, move to the lower half
                right = middle - 1;
            }
        }

        return left;
    }

private:
    bool canAllocateCandies(vector<int>& candies, long long k,int numOfCandies) {
        // initalize the total number of student or child that can be served
        long long int maxNumOfChildren = 0;

        for (int pileIndex = 0; pileIndex < candies.size(); pileIndex++) {
            maxNumOfChildren +=
                candies[pileIndex] /
                numOfCandies; // adding number of children we can add to the pile 
        }

        return maxNumOfChildren >=k;
    }
};