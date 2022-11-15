//TC: O(|s|)
//MC: O(1)

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        vector<int> freq(256, 0);
        int L = 0, R = 0, mx = 0, distinct = 0;
        while(s[R]){
            if(freq[s[R]] == 0) distinct++;
            freq[s[R]]++;
            while(distinct > k){
                if(freq[s[L]] == 1) distinct--;
                freq[s[L]]--;
                L++;
            }
            mx = max(mx, R - L + 1);
            R++;
        }
        return mx;
    }
};
