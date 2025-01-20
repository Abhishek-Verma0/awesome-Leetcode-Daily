

/***
 * T.C --- O(m*n) 
 * S.C ---O(m*n)
 */

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
            int n=mat.size(); // stores the size of row
            int m= mat[0].size(); // store the size of cols
            unordered_map<int,int>mp; // map to store the index of each element of the array for easier lookup
            for(int i=0;i<arr.size();i++){
                    mp[arr[i]]=i; // store the index of each elements in map
            }

            int minIdx = INT_MAX ;  // to store the min index of the row or cols at which the particuar row or col got completely painted 
            
            // this loop finds the minimum of the index from arr at which any row got completely painted
            for(int row=0;row<n;row++){
                int lastIdx= INT_MIN;
                for(int col=0;col<m;col++){
                    int val= mat[row][col]; // it finds the value in row at particular position
                    int idx= mp[val]; // this finds the index of the elemtnt from the map 
                    lastIdx= max(lastIdx,idx); // this gives us the max index at which the an row will be completely painted we can say lst index from array which will make the row completely painted
                }
                minIdx=min(lastIdx,minIdx); // this finds the minimum of the minIdx and the index at which a row becomes fully painted and updates the minIdx for the all rows 
            }


            // this loop is just similar to the upper one instead of row it finds the minimum idx of arr at which any column get completely painted 
            for(int col=0;col<m;col++){
                int lastIdx=INT_MIN;
                for(int row=0;row<n;row++){
                    int val=mat[row][col];
                    int idx= mp[val]; // gets index from array 

                    lastIdx=max(lastIdx,idx); // finds the last index of array which makes a column fully painted 
                }
                minIdx=min(minIdx,lastIdx); // gets the minimum idx at which any row or col was completely painted
            }

            return minIdx; // returns the min Index at which any row or col was completely painted 

    }
};