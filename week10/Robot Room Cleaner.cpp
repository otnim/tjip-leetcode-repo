class Solution{
public:
    vector<int> dir{-1, 0, 1, 0, -1}; // up, right, down, left
    map<pair<int, int>, bool> vis;
    void goBack(Robot& robot){
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

    void floodFill(int row, int col, int facingDir, Robot& robot){
        vis[{row, col}] = true;
        robot.clean();

        for(int i = 0; i < 4; i++){
            int newFacingDir = (facingDir + i) % 4;
            int r = row + dir[i];
            int c = col + dir[i+1];
            if(!vis({r, c}).count() && robot.move()){
                floodFill(r, c, newFacingDir, robot);
                goBack(robot);
            }
            robot.turnRight();
        }
    }

    void cleanRoom(Robot& robot){
        floodFill(0, 0, 0, robot); // assuming initial position at (0, 0)
        //3rd 0 means the robot initially facing up. Similarly, 1, 2 and 3 will mean facing right, down and left
    }
};
