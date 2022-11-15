//TC: O(m x n)
//MC: O(D), D -> maximum visited cell in a single DFS initialization

class Solution {
public:
    vector<int> dr{0, -1, 0, 1, 0};

    void dfs(int r, int c, vector<vector<char>>& board){
        board[r][c] = '.';
        for(int d = 0; d < 4; d++){
            int rr = r + dr[d];
            int cc = c + dr[d+1];
            if(rr < 0 || cc < 0 || rr >= board.size() || cc >= board[0].size() || board[rr][cc] == '.') continue;
            dfs(rr, cc, board);
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        int cnt = 0;

        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                if(board[r][c] == 'X'){
                    cnt++;
                    dfs(r, c, board);
                }
            }
        }

        return cnt;
    }
};
