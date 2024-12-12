/****2558. Take Gifts From the Richest Pile
Easy
Topics
Companies
Hint

You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:

    Choose the pile with the maximum number of gifts.
    If there is more than one pile with the maximum number of gifts, choose any.
    Leave behind the floor of the square root of the number of gifts in the pile. Take the rest of the gifts.

Return the number of gifts remaining after k seconds.

 

Example 1:

Input: gifts = [25,64,9,4,100], k = 4
Output: 29
Explanation: 
The gifts are taken in the following way:
- In the first second, the last pile is chosen and 10 gifts are left behind.
- Then the second pile is chosen and 8 gifts are left behind.
- After that the first pile is chosen and 5 gifts are left behind.
- Finally, the last pile is chosen again and 3 gifts are left behind.
The final remaining gifts are [5,8,9,4,3], so the total number of gifts remaining is 29.

Example 2:

Input: gifts = [1,1,1,1], k = 4
Output: 4
Explanation: 
In this case, regardless which pile you choose, you have to leave behind 1 gift in each pile. 
That is, you can't take any pile with you. 
So, the total gifts remaining are 4.
 */





class Solution {
public:
    long long pickGifts(vector<int>& g, int k) {
        // Create max-heap
        make_heap(g.begin(), g.end());
        for (int i = 0, x = INT_MAX; i < k && x > 1; i++) {
            // Pop max element
            pop_heap(g.begin(), g.end());
            x = g.back();
            // Update element
            g.back() = sqrt(g.back());
            push_heap(g.begin(), g.end());
        }
        // Return sum
        return accumulate(g.begin(), g.end(), 0LL);
    }
};
        