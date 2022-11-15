//TC: O(N * 2^N)
//MC: O(N * 2^N)

class Solution {
public:
    vector<vector<int>> powerSet;

    void generateSubsets(int pos, vector<int>& nums, vector<int>& subset){
        if(pos == nums.size()){
            powerSet.emplace_back(subset);
            return;
        }
        subset.emplace_back(nums[pos]);
        generateSubsets(pos+1, nums, subset);
        subset.pop_back();

        generateSubsets(pos+1, nums, subset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        generateSubsets(0, nums, subset);

        return powerSet;
    }
};
