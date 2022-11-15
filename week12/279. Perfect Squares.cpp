//TC: O(n x sqrt(n))   <-confused
//MC: O(n)

class Solution {
public:
    vector<int> dp;

    int getMin(int n){
        if(n == 0) return 0;
        if(n < 0) return INT_MAX;
        if(dp[n] != -1) return dp[n];

        int num = INT_MAX;
        for(int i = 1; i*i <= n; i++){
            num = min(num, 1 + getMin(n - i*i));
        }
        return dp[n] = num;
    }

    int numSquares(int n) {
        dp.resize(n+5, -1);

        return getMin(n);
    }
};
