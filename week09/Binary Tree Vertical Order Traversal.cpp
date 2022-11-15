//TC: O(N * logN)
//MC: O(N)

class Solution {
public:
    map<int, vector<tuple<int, int, int>>> mp;

    void traverse(TreeNode *root, int level, int colum, int& discoverTime){
        if(!root) return;
        mp[colum].push_back({level, discoverTime, root->val});

        traverse(root->left, level+1, colum-1, ++discoverTime);
        traverse(root->right, level+1, colum+1, ++discoverTime);
    }

    vector<vector<int>> verticalOrder(TreeNode *root) {
        int discoverTime = 0;
        traverse(root, 0, 0, discoverTime);
        vector<vector<int>> verticalList;

        for(auto it : mp){
            vector<tuple<int, int, int>> v = it.second;
            sort(v.begin(), v.end());
            vector<int> vec;
            for(auto tpl : v){
                vec.push_back(get<2>(tpl));
            }
            verticalList.push_back(vec);
        }
        return verticalList;
    }
};


/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
