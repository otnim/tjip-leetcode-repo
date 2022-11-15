//TC: O(N)
//MC: O(1)

class Solution {
public:
    int runInorder(TreeNode* root, int &k){
        if(!root) return -1;
        int val1 = runInorder(root->left, k);
        k--;
        if(k == 0) return root->val;
        int val2 = runInorder(root->right, k);

        return max(val1, val2);
    }

    int kthSmallest(TreeNode* root, int k) {
        return runInorder(root, k);
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
