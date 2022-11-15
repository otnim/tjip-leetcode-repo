//TC: O(logn)
//MC: O(logn)

class Solution {
public:
    long long MOD = 1000000007;

    long long bigMod(long val, long long power){
        if(power == 0) return 1;
        if(power&1) return (val * bigMod(val, power-1)) % MOD;
        long long x = bigMod(val, power/2);
        return (x*x) % MOD;
    }

    int maxNiceDivisors(int primeFactors) {
        long long n = primeFactors;
        if(n == 1) return 1;
        long long res;
        if(n%3 == 0) res = bigMod(3, n/3);
        if(n%3 == 1) res = 4 * bigMod(3, (n-4)/3);
        if(n%3 == 2) res = 2 * bigMod(3, (n-2)/3);

        return res % MOD;
    }
};
