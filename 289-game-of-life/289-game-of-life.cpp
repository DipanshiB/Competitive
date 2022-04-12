class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> currState;
        copy(board.begin(), board.end(), back_inserter(currState));
        int m = board.size(), n = board[0].size(); 
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int live = 0;
                //check up
                if(i != 0 && currState[i-1][j] == 1)
                    live++;
                //check down
                if(i != m-1 && currState[i+1][j] == 1)
                    live++;
                //check left
                if(j != 0 && currState[i][j-1] == 1)
                    live++;
                //check right
                if(j != n-1 && currState[i][j+1] == 1)
                    live++; 
                //check northwest
                if(i != 0 && j != 0 && currState[i-1][j-1] == 1)
                    live++;
                //check northeast
                if(i != 0 && j != n-1 && currState[i-1][j+1] == 1)
                    live++;
                //check southwest
                if(i != m-1 && j != 0 && currState[i+1][j-1] == 1)
                    live++;
                //check southeast
                if(i != m-1 && j != n-1 && currState[i+1][j+1] == 1)
                    live++;
                
                if(currState[i][j] == 1) {
                    if(live < 2 || live > 3)
                        board[i][j] = 0;
                }
                else {
                    if(live == 3) 
                        board[i][j] = 1;
                }
            }
        }
        //return board;
    }
};