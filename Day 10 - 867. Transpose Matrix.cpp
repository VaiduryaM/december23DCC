//Day 10 - 867. Transpose Matrix


class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {

        /*
        for(int i=0; i<matrix.size();i++){
             for(int j=i+1; j<matrix.size(); j++){
                 swap(matrix[i][j], matrix[j][i]);
             }
        }    

        return matrix;
        */

        
        vector<vector<int>> t(matrix[0].size(), vector<int>(matrix.size(), 0));
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                t[j][i] = matrix[i][j];
            }
        }

        return t;
        
        
    }
};