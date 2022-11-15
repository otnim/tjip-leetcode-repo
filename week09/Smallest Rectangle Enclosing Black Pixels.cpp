//TC: O(m x n)
//MC: O(D), D -> maximum visited cell in DFS initialization

class Solution {
public:
    vector<int> dr{0, -1, 0, 1, 0};
    int topRow, bottomRow, leftCol, rightCol;

    void dfs(int r, int c, vector<vector<char>>& image){
        image[r][c] = '0';
        topRow = min(topRow, r);
        bottomRow = max(bottomRow, r);
        leftCol = min(leftCol, c);
        rightCol = max(rightCol, c);

        for(int d = 0; d < 4; d++){
            int rr = r + dr[d];
            int cc = c + dr[d+1];
            if(rr < 0 || cc < 0 || rr >= image.size() || cc >= image[0].size() || image[rr][cc] == '0') continue;
            dfs(rr, cc, image);
        }
    }

    int minArea(vector<vector<char>> &image, int x, int y) {
        topRow = image.size(), bottomRow = 0, leftCol = image[0].size(), rightCol = 0;
        dfs(x, y, image);
        return (bottomRow - topRow + 1) * (rightCol - leftCol + 1);
    }
};
