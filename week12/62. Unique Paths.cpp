//TC: O(m x n)
//MC: O(n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp;
        dp.resize(2, vector<int>(n, 1));

        for(int row = 1; row < m; row++){
            for(int col = 1; col < n; col++){
                dp[1][col] = dp[1][col-1] + dp[0][col];
                dp[0][col] = dp[1][col];
            }
        }

        return dp[1][n-1];
    }
};
