/**326. Power of Three
Solved
Easy
Topics
Companies

Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

 

Example 1:

Input: n = 27
Output: true
Explanation: 27 = 33

Example 2:

Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.

Example 3:

Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).

 

Constraints:

    -231 <= n <= 231 - 1

 
Follow up: Could you solve it without loops/recursion? */


/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfThree = function(n) {
    if(n<=0){
        return false;
    }
    while(n%3==0){
        n/=3;
    }
    return n==1;
};



// without any loop or recursion


var isPowerOfThree = function(n) {
    let larg=1162261467;  // as 116261467 is largest 32 bit number which is power of three
    return n>0 && larg%n==0;
};
