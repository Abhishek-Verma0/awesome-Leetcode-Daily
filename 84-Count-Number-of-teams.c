/*1395. Count Number of Teams
Solved
Medium
Topics
Companies
Hint

There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

    Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
    A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).

Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).



Example 1:

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1).

Example 2:

Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.

Example 3:

Input: rating = [1,2,3,4]
Output: 4



Constraints:

    n == rating.length
    3 <= n <= 1000
    1 <= rating[i] <= 105
    All the integers in rating are unique.

*/

int numTeams(int *rating, int ratingSize)
{
    int count = 0;

    for (int j = 1; j < ratingSize - 1; ++j)
    {
        int leftLess = 0, leftGreater = 0, rightLess = 0, rightGreater = 0;

        for (int i = 0; i < j; ++i)
        {
            if (rating[i] < rating[j])
            {
                leftLess++;
            }
            else if (rating[i] > rating[j])
            {
                leftGreater++;
            }
        }

        for (int k = j + 1; k < ratingSize; ++k)
        {
            if (rating[k] < rating[j])
            {
                rightLess++;
            }
            else if (rating[k] > rating[j])
            {
                rightGreater++;
            }
        }

        count += leftLess * rightGreater + leftGreater * rightLess;
    }

    return count;
}
