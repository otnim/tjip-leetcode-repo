//TC: O(n)
//MC: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, mx = INT_MIN, L = 0, R = 0;

        while(R < nums.size()){
            sum += nums[R];
            R++;
            mx = max(mx, sum);
            while(L < R && sum < 0){
                sum -= nums[L];
                L++;
            }
        }

        return mx;
    }
};
