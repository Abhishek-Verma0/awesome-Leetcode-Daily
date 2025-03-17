
/**
 * T.C -> O(n)
 * S.C ->O(n)
 */

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();  // Get the total number of candies
        int eat = n / 2;           // Maximum candies Alice can eat (half of total)
        
        map<int, int> mp;          // Use a map to count unique candy types
        for(int i : candyType) {
            mp[i]++;               // Store the frequency of each candy type
        }
        
        int avail = mp.size();      // Count unique candy types

        if(avail < eat) {          // If unique types are less than the max Alice can eat
            return avail;          // She gets all unique types
        }
        return eat;                // Otherwise, she gets the max allowed (n/2)
    }
};
