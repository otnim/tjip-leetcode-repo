//TC: O(N)
//MC: O(N)

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> values;
        bool isOdd = 1;
        queue<TreeNode*> q; q.push(root);

        while(q.size()){
            int length = q.size();
            vector<int> v;
            for(int i = 1; i <= length; i++){
                TreeNode* u = q.front(); q.pop();
                v.push_back(u->val);

                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
            if(!isOdd){
                reverse(v.begin(), v.end());
            }
            isOdd = !isOdd;
            values.push_back(v);
        }
        return values;
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
