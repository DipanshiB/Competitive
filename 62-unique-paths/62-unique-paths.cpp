class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n ==1) return 1;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m-1][n-1] = 1;
        dp[m-2][n-1] = 1;
        dp[m-1][n-2] = 1;
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                int rightVal = 0, downVal = 0;
                if(dp[i][j] != 0) continue;
                if(i != m-1) {
                    downVal = dp[i+1][j];
                }
                if(j != n-1) {
                    rightVal = dp[i][j+1];
                }
                dp[i][j] = downVal + rightVal;
            }
        }
        return dp[0][0];
    }
};