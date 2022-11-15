//TC: O(|s|)
//MC: O(1)

class Solution {
public:
    int getMaxLen(string& s, int& k, int distinctChar){
        int distinctCharCnt = 0, freqAtLeastK = 0, L = 0, R = 0;
        vector<int> freq(130, 0);
        int maxLen = 0;

        while(s[R]){
            freq[s[R]]++;
            distinctCharCnt += freq[s[R]] == 1;
            freqAtLeastK += freq[s[R]] == k;
            R++;
            while(distinctCharCnt > distinctChar){
                distinctCharCnt -= freq[s[L]] == 1;
                freqAtLeastK -= freq[s[L]] == k;
                freq[s[L]]--;
                L++;
            }
            if(distinctChar <= freqAtLeastK) maxLen = max(maxLen, R-L);
        }
        return maxLen;
    }

    int longestSubstring(string s, int k) {
        int maxLen = 0;
        for(int i = 1; i <= 26; i++){
            maxLen = max(maxLen, getMaxLen(s, k, i));
        }

        return maxLen;
    }
};
