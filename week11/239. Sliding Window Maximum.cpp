//TC: O(n)
//MC: O(n)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> maxValues;

        for(int i = 0; i < nums.size(); i++){
            while(dq.size() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            while(dq.size() && dq.back() - dq.front() >= k) dq.pop_front();

            if(i+1 >= k) maxValues.push_back(nums[dq.front()]);
        }

        return maxValues;
    }
};
