//TC: O(N x L^N), where N = |digits| and L = max characters under each digit
//MC: O(N x L)

class Solution {
public:
    unordered_map<int, string> digitLetters;

    void getString(int pos, string& cur, string& digits, vector<string>& res){
        if(pos >= digits.size()){
            res.push_back(cur);
            return;
        }

        for(char ch : digitLetters[digits[pos]-'0']){
            cur.push_back(ch);
            getString(pos+1, cur, digits, res);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        digitLetters[2] = "abc";
        digitLetters[3] = "def";
        digitLetters[4] = "ghi";
        digitLetters[5] = "jkl";
        digitLetters[6] = "mno";
        digitLetters[7] = "pqrs";
        digitLetters[8] = "tuv";
        digitLetters[9] = "wxyz";

        vector<string> res;
        string cur = "";
        if(digits.size() == 0) return {};

        getString(0, cur, digits, res);
        cout<<res.size()<<endl;
        return res;
    }
};
