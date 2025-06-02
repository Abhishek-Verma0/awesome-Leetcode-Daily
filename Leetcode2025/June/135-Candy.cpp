class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        // Every child must receive at least one candy, so we start by giving one to everyone.
        vector<int> count(n, 1);

        // First pass: move from left to right.
        // If a child has a higher rating than the previous one, they should get more candies.
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                count[i] = count[i - 1] + 1;
            }
        }

        // Second pass: move from right to left.
        // This ensures that children with higher ratings than the next child
        // still get more candies, even after the first pass.
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                // We take the max here to avoid overwriting a higher value from the first pass.
                count[i] = max(count[i], count[i + 1] + 1);
            }
        }

        // Sum up all the candies to get the total required.
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += count[i];
        }

        return res;
    }
};
