//TC: O(N)
//MC: O(H), H -> max height of the tree

class Solution {
public:
    int maxSum;
    int getMaxPathSum(TreeNode* root){
        if(!root) return 0;
        int L = getMaxPathSum(root->left);
        int R = getMaxPathSum(root->right);
        maxSum = max(maxSum, L + R + root->val);

        return max(0, max(L, R) + root->val);

    }

    int maxPathSum(TreeNode* root) {
        maxSum = -1000000;
        getMaxPathSum(root);
        return maxSum;
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
