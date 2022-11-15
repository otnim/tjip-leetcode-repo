//TC: O(m x n)
//MC: O(D), D -> maximum visited cell in a single DFS initialization

class Solution {
public:
    vector<int> dr{0, -1, 0, 1, 0}; /// Left, Up, Right, Bottom direction

    void dfs(int r, int c, vector<vector<char>>& grid){
        grid[r][c] = '0';
        for(int d = 0; d < 4; d++){
            int rr = r + dr[d];
            int cc = c + dr[d+1];
            if(rr < 0 || cc < 0 || rr >= grid.size() || cc >= grid[0].size() || grid[rr][cc] == '0') continue;
            dfs(rr, cc, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size(), cnt = 0;

        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == '1'){
                    cnt++;
                    dfs(r, c, grid);
                }
            }
        }

        return cnt;
    }
};
