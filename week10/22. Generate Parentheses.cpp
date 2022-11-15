//TC: O(C(n)), C(n) := n'th catalan number
//MC: O(C(n))

class Solution {
public:
    vector<string> parentheses;

    void generateParentheses(int open, int close, string& cur){
        if(open == 0 && close == 0){
            parentheses.emplace_back(cur);
            return;
        }
        if(open){
            cur.push_back('(');
            generateParentheses(open-1, close, cur);
            cur.pop_back();
        }
        if(open < close){
            cur.push_back(')');
            generateParentheses(open, close-1, cur);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string cur = "";
        generateParentheses(n, n, cur);

        return parentheses;
    }
};
