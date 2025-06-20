class Solution {
public:
    // Function to calculate the maximum Manhattan distance with up to k moves changed
    int maxDistance(string s, int k) {
        int maxManDist = 0; // This will store the maximum Manhattan distance found
        int East = 0, West = 0, North = 0, South = 0; // Counters for each direction

        // Iterate through the input string s
        for (int i = 0; i < s.size(); i++) {
            // Count the direction at each step
            if (s[i] == 'E') East++;
            else if (s[i] == 'W') West++;
            else if (s[i] == 'N') North++;
            else if (s[i] == 'S') South++;

            // Calculate the current Manhattan Distance (difference in East-West + North-South)
            int currMd = abs(East - West) + abs(North - South);

            int step = i + 1; // Total steps taken so far (i is 0-indexed, so add 1)
            int wasted = step - currMd; // "Wasted" steps are those that cancel each other

            int ext = 0;
            // If there are wasted steps, we can improve the Manhattan Distance
            // by converting up to 2*k of them (each direction change can improve MD by at most 2)
            if (wasted != 0) {
                ext = min(wasted, 2 * k); // We can only fix up to 2*k wasted steps
            }

            // Final possible Manhattan Distance after changing up to k directions
            int finalCurrMd = currMd + ext;

            // Update the max if this step gives a higher distance
            maxManDist = max(maxManDist, finalCurrMd);
        }

        // return maximum Manhattan Distance got
        return maxManDist;
    }
};
