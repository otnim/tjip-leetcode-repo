//TC: O(logn)
//MC: O(logn)

class Solution {
public:
    double bigMod(double x, long long power){
        if(power == 0) return 1.0;

        if(power&1) return x * bigMod(x, power-1);
        double val = bigMod(x, power/2);
        return val*val;
    }

    double myPow(double x, int n) {
        bool isInverse = n < 0;
        long long power = abs(n);

        double res = bigMod(x, power);

        if(isInverse) res = 1/res;
        return res;
    }
};
