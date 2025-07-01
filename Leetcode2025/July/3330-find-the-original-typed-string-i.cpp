class Solution {
public:
    int possibleStringCount(string word) {
        int cnt=1; // for the full string we take 1  here as one case possible that no char was pressed multiple time 

        for(int i=1;i<word.size();i++){
            if(word[i]==word[i-1]){
                cnt++;
            }
        }
        return cnt;
    }
};
