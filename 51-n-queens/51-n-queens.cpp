class Solution {
public:
    
    bool check(int n, int row, int col, vector<string> temp) {
        //check row
        for(int i=0; i<col; i++) {
            if(temp[row][i] == 'Q')
                return false;
        }
        // //check column
        // for(int i=0; i<n; i++) {
        //     if(temp[i][col] == 'Q')
        //         return false;
        // }
        // //check south east diagonal
        // int i = row, j = col;
        // while(i >=0 && i < n && j < n && j >= 0) {
        //     if(temp[i][j] == 'Q') return false;
        //     i++;
        //     j++;
        // }
        
        int i = row, j = col;
        //check south west diagonal
        i = row, j = col;
        while(i >=0 && i < n && j < n && j >= 0) {
            if(temp[i][j] == 'Q') return false;
            i++;
            j--;
        }
        // //check north east diagonal
        // i = row, j = col;
        // while(i >=0 && i < n && j < n && j >= 0) {
        //     if(temp[i][j] == 'Q') return false;
        //     i--;
        //     j++;
        // }
        //check north west diagonal
        i = row, j = col;
        while(i >=0 && i < n && j < n && j >= 0) {
            if(temp[i][j] == 'Q') return false;
            i--;
            j--;
        }
        
      return true;
    }
    
    void fill(int col, int n, vector<string>& temp, vector<vector<string>>& res) {
        if(col == n) {
            res.push_back(temp);
            return;
        }
        //for every row in this column, try to place queen
        for(int i=0; i<n; i++) {
            //check if can place
            if(check(n, i, col, temp)) {
                //if yes, call fcn on next column after placing queen
                temp[i][col] = 'Q';
                fill(col+1, n, temp, res);
                temp[i][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> temp(n, string(n, '.'));
        fill(0, n, temp, res);
        return res;
    }
};