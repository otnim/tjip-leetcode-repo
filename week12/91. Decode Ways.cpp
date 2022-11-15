//TC: O(n)
//MC: O(n)

class Solution {
public:
    vector<int> ways;

    int cntWays(int pos, string& s){
        if(s[pos] == '0' || pos == s.size()) return pos == s.size();
        if(ways[pos] != -1) return ways[pos];

        int cnt = cntWays(pos+1, s);
        if(pos+1 < s.size() && (s[pos] - '0')*10 + s[pos+1]-'0' < 27) {
            cnt += cntWays(pos+2, s);
        }
        return ways[pos] = cnt;
    }

    int numDecodings(string s) {
        ways.resize(s.size()+5, -1);

        return cntWays(0, s);
    }
};
