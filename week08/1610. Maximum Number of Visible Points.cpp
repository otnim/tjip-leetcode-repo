//TC: O(nlogn)
//MC: O(n)

class Solution {
public:
    double getAngle(int dx, int dy){
        double radian = atan2(dy, dx);
        double degree = radian * (180/acos(-1));
        return degree < 0 ? degree + 360 : degree;
    }

    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> angles;
        int duplicate = 0;
        for(auto point : points){
            int dx = point[0] - location[0];
            int dy = point[1] - location[1];
            if(point == location) duplicate++;
            else angles.push_back(getAngle(dx, dy));
        }
        sort(angles.begin(), angles.end());
        int n = angles.size();

        int hi = 0, mx = 0;
        for(int lo = 0; lo < n; lo++){
            while((hi < n && angles[hi] - angles[lo] <= angle) || (hi >= n && 360 + angles[hi%n] - angles[lo] <= angle)){
                hi++;
            }

            mx = max(mx, hi - lo);
        }
        return mx + duplicate;
    }
};
