/**440. K-th Smallest in Lexicographical Order
Hard
Topics
Companies

Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

 

Example 1:

Input: n = 13, k = 2
Output: 10
Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.

Example 2:

Input: n = 1, k = 1
Output: 1

 

Constraints:

    1 <= k <= n <= 109

 */



var findKthNumber = function(n, k) {
    const getReqNum = (a, b, n) => {
        let gap = 0;
        while (a <= n) {
            gap += Math.min(n + 1, b) - a;
            a *= 10;
            b *= 10;
        }
        return gap;
    };

    let num = 1; 
    let i = 1;   

    while (i < k) {
        let req = getReqNum(num, num + 1, n);  
        if (i + req <= k) {
            i += req;
            num++;
        } else {
            i++;
            num *= 10;
        }
    }

    return num;  
};
