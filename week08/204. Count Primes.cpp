//TC: O(N * lnlnN), approximately
//MC: O(N)

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, 1);
        int cnt = 0;
        for(int i = 2; i < n; i++){
            if(isPrime[i]){
                cnt++;
                for(long long j = 1LL*i*i; j < 1LL*n; j += i) isPrime[j] = 0;
            }
        }
        return cnt;
    }
};
