//TC: O(log(row*colum))
//MC: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0, hi = matrix.size() * matrix[0].size() - 1;
        bool isFound = 0;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            int row = mid/matrix[0].size();
            int colum = mid % matrix[0].size();
            if(target == matrix[row][colum]) isFound = 1;
            if(target > matrix[row][colum]) lo = mid + 1;
            else hi = mid - 1;
        }
        return isFound;
    }
};
