/// Iterative approach
//TC: O(n x m), m := amount
//MC: O(m)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> minWays(amount+5, INT_MAX/5);
        minWays[0] = 0;

        for(int coin : coins){
            for(int i = coin; i <= amount; i++){
                minWays[i] = min(minWays[i], 1 + minWays[i-coin]);
            }
        }

        return minWays[amount] > amount ? -1 : minWays[amount];
    }
};



/// Recursive approach

//TC: O(n*m), where n := total unique coin, m := amount
//MC: O(n*m)

class Solution {
public:
    vector<vector<int>> dp;
    int minNeededCoin(int pos, int rem, vector<int>& coins){
        if(rem == 0) return 0;
        if(rem < 0 || pos >= coins.size()) return INT_MAX/5;
        if(dp[pos][rem] != -1) return dp[pos][rem];

        int minCnt = minNeededCoin(pos+1, rem, coins); //moving forward not taking pos'th coin
        minCnt = min(minCnt, 1 + minNeededCoin(pos, rem - coins[pos], coins)); //not moving but taking pos'th coin
        minCnt = min(minCnt, 1 + minNeededCoin(pos+1, rem - coins[pos], coins)); //moving forward taking pos'th coin

        return dp[pos][rem] = minCnt;
    }

    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size()+5, vector<int>(amount+5, -1));

        int minCnt = minNeededCoin(0, amount, coins);

        return minCnt > amount ? -1 : minCnt;
    }
};
