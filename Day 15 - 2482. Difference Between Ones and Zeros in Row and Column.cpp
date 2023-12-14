//Day 15 - 2482. Difference Between Ones and Zeros in Row and Column


class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {

        
        // my sol
        vector<vector<int>> diff(grid.size(), vector<int>(grid[0].size(), 0));
        map<int,int> onesRow, onesCol, zerosRow, zerosCol;

        for(int i=0; i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1) onesRow[i]++;
                //if(grid[i][j] == 0) zerosRow[i]++;
            }
            zerosRow[i] = grid.size()-onesRow[i];
        }

        for( int i=0; i<grid[0].size();i++){
            for(int j=0; j<grid.size();j++){
                if(grid[j][i] == 1) onesCol[i]++;
                //if(grid[j][i] == 0) zerosCol[j]++;
            }
            zerosCol[i] = grid[0].size() - onesCol[i];
        }


        for(int i=0;i<grid.size();i++){
            for(int j=0; j<grid[0].size();j++){
                diff[i][j] = onesRow[i]+onesCol[j]-zerosRow[i]-zerosCol[j];
            }
        }

        return diff;
        

                /*
        //from editorial
        int m = grid.size();
        int n = grid[0].size();

        vector<int> onesRow(m,0);
        vector<int> onesCol(n,0);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                onesRow[i] += grid[i][j];
                onesCol[j] += grid[i][j];
            }
        }

        vector<vector<int>> diff(grid.size(), vector<int>(grid[0].size(), 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                diff[i][j] = 2*onesRow[i]+2*onesCol[j]-n-m;
            }
        }

        return diff;
        */

    }
};