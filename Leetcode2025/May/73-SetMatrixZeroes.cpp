class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();  
        int m=matrix[0].size();
        vector<bool>row(n,false); //row array to track which row has zero
        vector<bool>col(m,false); // col array to keep track which col has zero
        //  marking which row or column has zero
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row[i]=true;
                    col[j]=true;
                }
            }
        }

        //  set entire row zero for the marked rows
        for(int i=0;i<n;i++){
            if(row[i]){
                for(int j=0;j<m;j++){
                    matrix[i][j]=0;
                }
            }
        }
        //  set entire col zero for the marked col
        for(int i=0;i<m;i++){
            if(col[i]){
                for(int j=0;j<n;j++){
                    matrix[j][i]=0;
                }
            }
        }

        }
    
};
