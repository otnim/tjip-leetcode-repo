//TC: O(n)
//MC: O(1)

class Solution {
public:
    int jump(vector<int>& nums) {
        int minStep = 0, maxReach = 0, lo = 0, hi = 0;

        while(hi+1 < nums.size()){
            for(int i = lo; i <= hi; i++){
                maxReach = max(maxReach, i + nums[i]);
            }
            lo = hi + 1;
            hi = maxReach;
            minStep++;
        }

        return minStep;
    }
};
