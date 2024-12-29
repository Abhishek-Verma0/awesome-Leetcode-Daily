/***7. Reverse Integer
Solved
Medium
Topics
Companies

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321

Example 3:

Input: x = 120
Output: 21

 

Constraints:

    -231 <= x <= 231 -  */





class Solution {
public:
    int reverse(int x) {


        int dp=0;
        while(x!=0){
            
            int rem=x%10;
            // this checks whether number while revrsing goes out for 64 bit number 
            //chcecks for overflow and underflow
            if((dp> INT_MAX /10) || (dp < INT_MIN / 10) ){
                return 0;
            }
            dp= dp*10+rem;
            x/=10;
        }

        return dp;
    }
};