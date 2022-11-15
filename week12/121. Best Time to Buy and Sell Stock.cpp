//TC: O(n)
//MC: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, minVal = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            profit = max(profit, prices[i] - minVal);
            minVal = min(minVal, prices[i]);
        }
        return profit;
    }
};
