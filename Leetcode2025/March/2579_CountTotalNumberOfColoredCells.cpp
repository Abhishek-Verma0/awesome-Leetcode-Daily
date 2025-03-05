/***
 * T.C -- O(1)
 * S.C --- O(1)
 */


class Solution {
public:
    long long coloredCells(int n) {
        long long num=n;
        long long  res= 2*num *(num-1) +1;
        return res;
       
    }
};