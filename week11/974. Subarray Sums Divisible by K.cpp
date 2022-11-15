//TC: O(n)
//MC: O(k)

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> seen(k+1, 0);
        seen[0] = 1;
        int cnt = 0, prefSum = 0;

        for(int i = 0; i < nums.size(); i++){
            prefSum += nums[i];
            if(prefSum < 0) prefSum += (-k*prefSum);
            prefSum %= k;
            cnt += seen[prefSum];
            seen[prefSum]++;
        }
        return cnt;
    }
};
