//TC: O(N)
//MC: O(1)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val == p->val || root->val == q->val) return root;

        TreeNode* lft = lowestCommonAncestor(root->left, p, q);
        TreeNode* rht = lowestCommonAncestor(root->right, p, q);

        if(lft && rht) return root;
        return rht ? rht : lft;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
