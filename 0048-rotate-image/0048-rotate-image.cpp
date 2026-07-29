class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp(matrix.size(),vector<int>(matrix.size(),0));
        int i=matrix[0].size()-1;
        int j=0;
        int q=0;
        while(j<matrix.size()){
            i = matrix[0].size()-1;
            q=0;
            while(i>=0&&q<matrix.size()){
                temp[j][q]=matrix[i][j];
                i--;
                q++;
            }
            j++; 
        }

        matrix = temp;

        return ;

    }
};