/**214. Shortest Palindrome
Solved
Hard
Topics
Companies

You are given a string s. You can convert s to a
palindrome
by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

 

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"

Example 2:

Input: s = "abcd"
Output: "dcbabcd"

 

Constraints:

    0 <= s.length <= 5 * 104
    s consists of lowercase English letters only.

 */



/**
 * @param {string} s
 * @return {string}
 */
var shortestPalindrome = function(s) {
    let count = comp(s.split('').reverse().join(''), s);
    return s.slice(count).split('').reverse().join('') + s;
};

var comp = function(txt, pattern) {
    let newString = pattern + '#' + txt;
    let pi = new Array(newString.length).fill(0);
    let i = 1, k = 0;
    while (i < newString.length) {
        if (newString[i] === newString[k]) {
            k++;
            pi[i] = k;
            i++;
        } else {
            if (k > 0) {
                k = pi[k - 1];
            } else {
                pi[i] = 0;
                i++;
            }
        }
    }
    return pi[newString.length - 1];
};
