//TC: O(row*col*3^L), L = word length
//MC: O(row*col)

class Solution {
public:
    vector<vector<bool>> vis;
    vector<int> dir{0, -1, 0, 1, 0};

    bool findWord(int r, int c, int index, string& word, vector<vector<char>>& board){
        if(index+1 == word.size()) return true;
        char ch = word[index+1];
        bool status = 0;
        for(int d = 0; d < 4; d++){
            int rr = r + dir[d];
            int cc = c + dir[d+1];
            if(rr >= 0 && rr < board.size() && cc >= 0 && cc < board[0].size() && !vis[rr][cc] && board[rr][cc] == ch){
                vis[rr][cc] = 1;
                status |= findWord(rr, cc, index+1, word, board);
                vis[rr][cc] = 0;
            }
        }
        return status;

    }

    bool exist(vector<vector<char>>& board, string word) {
        bool status = 0;
        vis.resize(board.size());

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){

                for(int k = 0; k < vis.size(); k++){
                    vis[k].clear();
                    for(int l = 0; l < board[0].size(); l++){
                        vis[k].push_back(0);
                    }
                }
                if(board[i][j] == word[0]) {
                    vis[i][j] = 1;
                    status |= findWord(i, j, 0, word, board);
                }
            }
        }
        return status;
    }
};
