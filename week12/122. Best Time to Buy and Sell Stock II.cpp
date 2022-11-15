//TC: O(n)
//MC: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;
        for(int i = 0; i+1 < prices.size(); i++){
            int rht = i, last = prices[i];
            while(rht+1 < prices.size() && last <= prices[rht+1]){
                last = prices[rht+1];
                rht++;
            }
            totalProfit += prices[rht] - prices[i];
            i = rht;
        }
        return totalProfit;
    }
};
