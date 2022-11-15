class Solution {
public:
    bool isSolutionFound, hr[9][10], vr[9][10], sq[3][3][10];
    /**hr[i][j] = 1 means, i'th row te j bosano hoyeche
    vr[i][j] = 1 means, i'th col e j bosano hoyeche

    sq[p][q][j] = 1 means p,q sub-square e j bosano hoyeche (total sub-square 9 ta).
            0,0 | 0,1 | 0,2
            ----------------
            1,0 | 1,1 | 1,2
            ----------------
            2,0 | 2,1 | 2,2
    */

    void fillGrid(int cellNo, vector<vector<char>>& board){
        if(cellNo > 80) {
            isSolutionFound = 1;
            return;
        }

        int row = cellNo/9, col = cellNo%9;
        int sqRow = row/3, sqCol = col/3;

        if(board[row][col] != '.'){
            fillGrid(cellNo+1, board);
        }
        else{
            for(int i = 1; i <= 9; i++){
                if(!hr[row][i] && !vr[col][i] && !sq[sqRow][sqCol][i]){
                    board[row][col] = char(i + '0');
                    hr[row][i] = 1;
                    vr[col][i] = 1;
                    sq[sqRow][sqCol][i] = 1;

                    fillGrid(cellNo+1, board);

                    if(!isSolutionFound){
                        board[row][col] = '.';
                        hr[row][i] = 0;
                        vr[col][i] = 0;
                        sq[sqRow][sqCol][i] = 0;
                    }
                }
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                if(board[r][c] != '.') {
                    int sqRow = r/3, sqCol = c/3;
                    int val = board[r][c] - '0';
                    hr[r][val] = 1;
                    vr[c][val] = 1;
                    sq[sqRow][sqCol][val] = 1;
                }
            }
        }

        fillGrid(0, board);
    }
};
