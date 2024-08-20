/**1140. Stone Game II
Solved
Medium
Topics
Companies
Hint

Alice and Bob continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones. 

Alice and Bob take turns, with Alice starting first.  Initially, M = 1.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

 

Example 1:

Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 

Example 2:

Input: piles = [1,2,3,4,5,100]
Output: 104

 

Constraints:

    1 <= piles.length <= 100
    1 <= piles[i] <= 104

 */



const n = piles.length;

    const suffixSum = new Array(n).fill(0);

    suffixSum[n - 1] = piles[n - 1];

    for (let ind = n - 2; ind >= 0; ind--) {

      suffixSum[ind] = suffixSum[ind + 1] + piles[ind];

    }


    const dp = new Array(n).fill(0).map(() => new Array(n + 1).fill(0));


    for (let ind = n - 1; ind >= 0; ind--) {

      for (let possibleM = 1; possibleM <= n; possibleM++) {

        if (ind + possibleM * 2 >= n) { // Alice can take all stones

          dp[ind][possibleM] = suffixSum[ind];

        } else {

          for (let takeStones = 1; takeStones <= 2 * possibleM; takeStones++) {

            dp[ind][possibleM] = Math.max(dp[ind][possibleM], suffixSum[ind] - dp[ind + takeStones][Math.max(possibleM, takeStones)]);

          }

        }

      }

    }


    return dp[0][1];

  }