/***
 * T.C -> O(n)
 * S.C -> O(1)
 */


class Solution {
public:
    bool judgeCircle(string moves) {
        int n=moves.size();
        if(n==1 ||0){
            return false;
        }
        int x=0;
        int y=0;
        for (char ch : moves){
            if(ch=='U'){
                y++;
            }
            else if(ch=='D'){
                y--;
            }
            else if(ch=='R'){
                x++;
            }
            else if(ch=='L'){
                x--;
            }
            else{
                continue;
            }
        }
        return (x==0 && y==0) ? true : false;
    }
};