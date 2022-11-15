//TC: O(n)
//MC: O(H), H -> max height of the tree

class Solution {
public:
    bool isValidOrder(int& pos, int lo, int hi, vector<int>& preorder){
        if(pos == preorder.size()) return true;
        int curVal = preorder[pos];
        if(curVal <= lo || curVal >= hi) return false;
        pos++;
        bool isLeftInsertionPossible = isValidOrder(pos, lo, curVal, preorder);
        bool isRightInsertionPossible = isValidOrder(pos, curVal, hi, preorder);
        return isLeftInsertionPossible || isRightInsertionPossible;
    }

    bool verifyPreorder(vector<int> &preorder) {
        int pos = 0;
        return isValidOrder(pos, INT_MIN, INT_MAX, preorder);
    }
};
