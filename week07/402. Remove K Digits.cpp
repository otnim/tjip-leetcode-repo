//TC: O(|num|)
//MC: O(|num|)

class Solution {
public:
    void eraseDigit(string& num, int& k){
        string res = "";
        for(char ch : num){
            while(res.size() && res.back() > ch && k){
                res.pop_back();
                k--;
            }
            res.push_back(ch);
        }
        (k && res.size() == 1) ? (num = "") : (num = res);
    }

    string removeKdigits(string num, int k) {
        eraseDigit(num, k);

        num.erase(0, num.find_first_not_of('0'));
        reverse(num.begin(), num.end());

        eraseDigit(num, k);

        reverse(num.begin(), num.end());

        if(k) num = num.substr(0, num.size()-k);
        return num == "" ? "0" : num;
    }
};
