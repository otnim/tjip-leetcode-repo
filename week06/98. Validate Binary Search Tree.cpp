//TC: O(N)
//MC: O(1)

class Solution {
public:
    bool isValidBST(TreeNode* root, long long lo = LONG_MIN, long long hi = LONG_MAX) {
        if(root == NULL) return true;
        if(root->val <= lo || root->val >= hi) return false;

        return isValidBST(root->left, lo, root->val) & isValidBST(root->right, root->val, hi);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
