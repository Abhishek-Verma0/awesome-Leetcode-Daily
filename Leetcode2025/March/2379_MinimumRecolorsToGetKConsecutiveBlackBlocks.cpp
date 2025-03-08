/***
 * 
 */



class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        queue<char>bl;
        int wh=0;
        while(bl.size()<k){
            char curr=blocks[bl.size()];
            if(curr=='W'){
                wh++;
            }
            bl.push(curr);
        }

        int re=wh;
        for(int i=k;i<blocks.size();i++){

            if(bl.front()=='W'){
                wh--;
            }
            bl.pop();
            if(blocks[i]=='W'){
                wh++;
            }
            bl.push(blocks[i]);
            re=min(re,wh);
        }
        return re;
    }
};