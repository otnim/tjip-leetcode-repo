//TC: O(N)
//MC: O(1)

class Solution {
public:
    TreeNode* createTree(vector<int>& nums, int lo, int hi){
        if(lo > hi) return NULL;
        int mid = lo + (hi - lo)/2;
        TreeNode* root = new TreeNode(nums[mid], createTree(nums, lo, mid-1), createTree(nums, mid+1, hi));

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createTree(nums, 0, nums.size()-1);
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
