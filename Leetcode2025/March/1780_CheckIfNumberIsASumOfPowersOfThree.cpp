/**
 * T.C -->> O(n) - n length of the given number
 * S.C --> O(1) -- coonstant as no extra space is used 
 *  */


class Solution {
public:
    bool checkPowersOfThree(int n) {
        /* to do this question we use hint of ternary representation which has base of 
        3 like 10 in decimal 
        We know if ternary representation of number has 2 then it can't represented with sum of 
        distinct power of 3   having 2 means power is repeated sort of thing
        We simply convert numner into ternary while doing so we will check if digit is 2 then return false
        else return true
       */
        
        while(n>0){
            int rem=n%3;
            if(rem==2){ // can't have 2 in ternary for the distinct sum of power of three represnetation
                return false;
            }
           
            n/=3;

        }
        return true;
    }
};