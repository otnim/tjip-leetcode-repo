//TC: O(N + Q * logN)  -> Q = total query
//MC: O(N)

class Solution {
public:
    vector<int> sw;
    mt19937 rd;

    Solution(vector<int>& w) {
        sw = w;
        for(int i = 1; i < (int)sw.size(); i++){
            sw[i] += sw[i-1];
        }
    }

    int pickIndex() {
        int sum = sw.back();
        int randVal = rd() % sum;

        return lower_bound(sw.begin(), sw.end(), randVal + 1) - sw.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
