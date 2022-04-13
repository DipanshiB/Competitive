class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> grid(n, vector<int>(n));
        int r1 = 0, r2 = n-1;
        int c1 = 0, c2 = n-1;
        int val = 0;
        while(r1 <= r2 && c1 <= c2) {
            //filling left to right
            for(int j=c1; j<=c2; j++) {
                grid[r1][j] = ++val;
            }
            //filling up to down
            for(int i=r1+1; i<=r2; i++) {
                grid[i][c2] = ++val;
            }
            //filling right to left
            for(int j=c2-1; j>=c1; j--) {
                grid[r2][j] = ++val;
            }
            //filling down to up
            for(int i=r2-1; i>r1; i--) {
                grid[i][c1] = ++val;
            }
            r1++;
            c1++;
            r2--;
            c2--;
        }
        return grid;
    }
};