//TC: O(log5(n)), 5 used here as a base
//MC: O(1)

class Solution {
public:
    int trailingZeroes(int n) {
        int cnt_5 = 0, div = 5;

        while(div <= n){
            cnt_5 += n/div;
            div *= 5;
        }

        return cnt_5;
    }
};
