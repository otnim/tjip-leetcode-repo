//TC: O(n^2)
//MC: O(n^2)

class Solution {
public:
    vector<int> dp;

    int getLIS(int pos, vector<int>& nums){
        if(pos >= nums.size()) return 0;
        if(dp[pos]) return dp[pos];

        int MX = 0;
        for(int i = pos+1; i < nums.size(); i++){
            if(nums[pos] < nums[i]){
                MX = max(MX, 1 + getLIS(i, nums));
            }
        }
        return dp[pos] = MX;
    }

    int lengthOfLIS(vector<int>& nums) {
        dp.clear();
        dp.resize(nums.size()+5, 0);
        int MX = 0;
        for(int i = 0; i < nums.size(); i++){
            MX = max(MX, 1 + getLIS(i, nums));
        }
        return MX;
    }
};
