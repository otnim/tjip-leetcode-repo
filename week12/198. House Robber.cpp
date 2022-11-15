//TC: O(n)
//MC: O(n)

class Solution {
public:
    vector<int> dp;

    int getMaxAmount(int pos, vector<int>& nums){
        if(pos >= nums.size()) return 0;
        if(dp[pos] != -1) return dp[pos];

        int maxAmount = nums[pos] + getMaxAmount(pos+2, nums);
        maxAmount = max(maxAmount, getMaxAmount(pos+1, nums));

        return dp[pos] = maxAmount;
    }

    int rob(vector<int>& nums) {
        dp.resize(nums.size()+5, -1);

        return getMaxAmount(0, nums);
    }
};
