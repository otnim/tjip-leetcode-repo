//TC: O(N)
//MC: O(N)

class Solution {
public:
    vector<int> dr{0, -1, 0, 1, 0};

    void wallsAndGates(vector<vector<int>>& rooms){
        queue<pair<int, int>> q;
        for(int i = 0; i < rooms.size(); i++){
            for(int j = 0; j < rooms[i].size(); j++){
                if(rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while(q.size()){
            auto u = q.front(); q.pop();
            int r = u.first, c = u.second;
            for(int i = 0; i < 4; i++){
                int rr = r + dr[i];
                int cc = c + dr[i+1];
                if(rr >= 0 && cc >= 0 && rr < rooms.size() && cc < rooms[0].size()){
                    if(rooms[r][c] + 1 < rooms[rr][cc]){
                        rooms[rr][cc] = rooms[r][c] + 1;
                        q.push({rr, cc});
                    }
                }
            }
        }
    }
};
