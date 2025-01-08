/**476. Number Complement
Solved
Easy
Topics
Companies

The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

    For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.

Given an integer num, return its complement.

 

Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

Example 2:

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.

 

Constraints:

    1 <= num < 231
 */


/**
 * @param {number} num
 * @return {number}
 */
var findComplement = function(num) {
    let k="";
    if(num==0){
        return 1;
    }
    
        while(num>0){
            k=(num%2==0 ? "1" : "0") +k
            num=Math.floor(num/2);
        }
    
    for(let i=0;i<k.length;i++){
        if(k[i]=="1"){
            k[i]="0";
        }
        else{
            k[i]="1";
        }
    }
    let base=1;
    let decimal=0;
    for(let i=k.length - 1;i>=0;i--){
        if(k[i]=="1"){
            decimal+=base
        };
        base*=2;
    }
    return decimal;
    
};