//TC: O(n) where n := 1000000
//MC: O(n)

class Solution {
public:
    vector<int> dp;
    int getPower(int n){
        if(n == 1) return 0;
        if(dp[n] != -1) return dp[n];

        if(n&1) return dp[n] = 1 + getPower((3*n) + 1);
        return dp[n] = 1 + getPower(n/2);
    }

    int getKth(int lo, int hi, int k) {
        dp.resize(1000000, -1);
        vector<pair<int, int>> powVal;

        for(int i = lo; i <= hi; i++){
            getPower(i);
            powVal.push_back({dp[i], i});
        }
        sort(powVal.begin(), powVal.end());

        return powVal[k-1].second;
    }
};
