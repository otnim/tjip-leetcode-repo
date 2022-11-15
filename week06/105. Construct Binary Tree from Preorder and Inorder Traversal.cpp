//TC: O(N)
//MC: O(N)

class Solution {
public:
    TreeNode* createTree(int &pos, int lo, int hi, vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& mp){
        if(lo > hi) return NULL;

        TreeNode* root = new TreeNode(preorder[pos++]);
        int mid = mp[root->val];

        TreeNode* lft = createTree(pos, lo, mid-1, preorder, inorder, mp);
        TreeNode* rht = createTree(pos, mid+1, hi, preorder, inorder, mp);
        root->left = lft;
        root->right = rht;

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        int pos = 0;
        return createTree(pos, 0, inorder.size()-1, preorder, inorder, mp);
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
