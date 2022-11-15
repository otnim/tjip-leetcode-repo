//TC: O(N)
//TC: O(N)

class Solution {
public:
    void inorderTraverse(TreeNode* root, int level, vector<pair<int, int>>& nodes){
        if(!root) return;

        inorderTraverse(root->left, level+1, nodes);
        nodes.push_back({root->val, level});
        inorderTraverse(root->right, level+1, nodes);
    }

    bool isSymmetric(TreeNode* root) {
        vector<pair<int, int>> nodes;
        inorderTraverse(root, 0, nodes);
        bool isSymmetric = 1;
        int N = nodes.size();

        for(int i = 0; i < N/2; i++) {
            if(nodes[i] != nodes[N-i-1]) isSymmetric = 0;
        }
        return isSymmetric;
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
