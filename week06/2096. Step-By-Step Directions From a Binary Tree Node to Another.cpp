//TC: O(N)
//MC: O(N), for storing the path string

class Solution {
public:
    TreeNode* findLCA(TreeNode* root, int &startValue, int &destValue){
        if(!root) return NULL;
        if(root->val == startValue || root->val == destValue) return root;

        TreeNode* lft = findLCA(root->left, startValue, destValue);
        TreeNode* rht = findLCA(root->right, startValue, destValue);

        if(lft && rht) return root;

        return lft ? lft : rht;
    }

    void findPartialPath(TreeNode* root, string &path, string &partialPath, int value, bool isStart = 0){
        if(!root) return;
        if(root->val == value) {
            partialPath = path;
            return;
        }

        if(isStart) path.append("U");
        else path.append("L");
        findPartialPath(root->left, path, partialPath, value, isStart);
        path.pop_back();

        if(isStart) path.append("U");
        else path.append("R");
        findPartialPath(root->right, path, partialPath, value, isStart);
        path.pop_back();
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = findLCA(root, startValue, destValue);

        string path = "", partialPath = "", finalPath;
        findPartialPath(LCA, path, partialPath, startValue, 1);
        finalPath = partialPath;

        path = partialPath = "";
        findPartialPath(LCA, path, partialPath, destValue);
        finalPath += partialPath;

        return finalPath;
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
