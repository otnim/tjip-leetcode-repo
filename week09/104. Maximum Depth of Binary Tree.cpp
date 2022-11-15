//TC: O(N)
//MC: O(1)

class Solution {
public:
    int maxDepth(TreeNode* root, int depth = 0) {
        if(!root) return 0;

        return 1 + max(maxDepth(root->left, depth+1), maxDepth(root->right, depth+1));
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
