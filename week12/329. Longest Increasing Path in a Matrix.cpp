//TC: O(m x n)
//MC: O(m x n)

class Solution {
public:
    vector<int> dir{0, -1, 0, 1, 0};
    vector< vector<int> > dp;

    int getLIP(int r, int c, vector<vector<int>>& matrix){
        if(dp[r][c] != -1) return dp[r][c];
        //dp[r][c] means r,c cell theke LIP

        int curMaxPathLen = 1;
        for(int i = 0; i < 4; i++){
            int rr = r + dir[i];
            int cc = c + dir[i+1];
            if(rr >= 0 && rr < matrix.size() && cc >= 0 && cc < matrix[0].size() && matrix[r][c] < matrix[rr][cc]){
                curMaxPathLen = max(curMaxPathLen, 1 + getLIP(rr, cc, matrix));
            }
        }

        return dp[r][c] = curMaxPathLen;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp.resize(matrix.size(), vector<int>(matrix[0].size(), -1));
        int row = matrix.size(), col = matrix[0].size();
        int maxPathLen = 1;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                maxPathLen = max(maxPathLen, getLIP(i, j, matrix));
            }
        }

        return maxPathLen;
    }
};
