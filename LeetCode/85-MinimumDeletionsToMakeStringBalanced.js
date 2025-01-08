/**1653. Minimum Deletions to Make String Balanced
Solved
Medium
Topics
Companies
Hint

You are given a string s consisting only of characters 'a' and 'b'​​​​.

You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

Return the minimum number of deletions needed to make s balanced.

 

Example 1:

Input: s = "aababbab"
Output: 2
Explanation: You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").

Example 2:

Input: s = "bbaaaaabb"
Output: 2
Explanation: The only solution is to delete the first two characters.

 

Constraints:

    1 <= s.length <= 105
    s[i] is 'a' or 'b'​​.

 */


var minimumDeletions = function (s) {
  const dpA = [];
  let counter = 0;
  for (let i = 0; i < s.length; i++) {
    dpA[i] = counter;
    if (s[i] === "b") {
      counter++;
    }
  }

  counter = 0;
  const dpB = [];
  for (let i = s.length - 1; i >= 0; i--) {
    dpB[i] = counter;
    if (s[i] === "a") {
      counter++;
    }
  }

  let minDelete = s.length;
  for (let i = 0; i < s.length; i++) {
    minDelete = Math.min(minDelete, dpA[i] + dpB[i]);
  }

  return minDelete;
};