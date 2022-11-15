//TC: O(n^2)
//MC: O(n^2)

class Solution {
public:
    vector<vector<bool>> isPalindrome;

    string longestPalindrome(string s) {
        int n = s.size();
        isPalindrome.resize(n+5, vector<bool>(n+5, 0));
        for(int i = 0; i < n; i++) isPalindrome[i][i] = 1;
        int maxPalLen = 1, leftIdx = 0;

        for(int i = 1; i < n; i++){
            int lft = 0;
            for(int rht = i; rht < n; rht++){
                if(rht-lft == 1) isPalindrome[lft][rht] = (s[lft] == s[rht]);
                else isPalindrome[lft][rht] = (s[lft] == s[rht]) && isPalindrome[lft+1][rht-1];
                if(isPalindrome[lft][rht] && rht-lft+1 > maxPalLen){
                    leftIdx = lft;
                    maxPalLen = rht-lft+1;
                }
                lft++;
            }
        }

        return s.substr(leftIdx, maxPalLen);
    }
};
