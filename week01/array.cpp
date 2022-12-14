//1. Two Sum
//TC: O(n)
//MC: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sz = nums.size();
        map<int, int> mp;
        //for(int i = 0; i < sz; i++) mp[nums[i]] = i;
        for(int i = 0; i < sz; i++){
            if(mp.find(target - nums[i]) != mp.end() && i != mp[target-nums[i]]){
                return {i, mp[target-nums[i]]};
            }mp[nums[i]] = i;
        }
        return {};
    }
};



//15. 3Sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i < n-2; i++){

            int lft = i+1, rht = n-1;
            while(lft < rht){
                if(nums[i] + nums[lft] + nums[rht] == 0) {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[lft]);
                    v.push_back(nums[rht]);
                    res.push_back(v);
                    while(lft < rht-1 && nums[lft] == nums[lft+1]) lft++;
                    while(rht > lft && nums[rht] == nums[rht-1]) rht--;
                }

                int rem = 0 - nums[i];
                if(rem < nums[lft] + nums[rht]) rht--;
                else lft++;
            }
            while(i < n-1 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};



//18. 4Sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector< vector< pair<int, int> > > pos; //2D vector, stores pair of int
        int cntIndex = 0;
        map<int, int> mp;
        set< vector<int> > res;
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 1; i < sz-1; i++){
            for (int j = i+1; j < sz; j++){
                int rhtValue = nums[i] + nums[j];
                int lftValue = target - rhtValue;
                if(mp.count(lftValue)){ // lftValue map e ache kina
                    int index = mp[lftValue];
                    int posSize = pos[index].size(); // lftValue kon vector e ache
                    //lftValue = 8 hole, 4+4 or 5+3 evabe 8 hote pare
                    // ejonno nicher loop diye sobgulo value result e add korchi
                    for(int k = 0; k < posSize; k++){
                        auto it = pos[index][k];
                        int x = it.first, y = it.second;
                        res.insert({x, y, nums[i], nums[j]});
                    }
                }
            }

            for(int l = 0; l < i; l++){
                int cur = nums[l] + nums[i];
                if(mp.count(cur)){
                    int index = mp[cur];
                    bool isFound = 0;
                    for(int k = 0; k < pos[index].size(); k++){
                        auto it = pos[index][k];
                        int x = it.first, y = it.second;
                        if(x == nums[l] && y == nums[i]) isFound = 1;
                    }
                    // aage ei pair ta store kora thakle ekhon ar store korbona
                    if(!isFound) pos[index].push_back({nums[l], nums[i]});
                }
                else{
                    vector<pair<int, int> > v;
                    v.push_back({nums[l], nums[i]});
                    pos.push_back(v);
                    mp[cur] = cntIndex;
                    cntIndex++;
                }
            }
        }
        vector< vector<int> > vec;
        for(auto it : res) vec.push_back(it);
        return vec;;
    }
};



//41. First Missing Positive
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int res = 1, sz = nums.size();
        for(int i = 0; i < sz; i++) {
            if(nums[i] == 1) res = 2;
            if(nums[i] <= 0) nums[i] = 1;
        }
        if(res != 1){
            for(int i = 0; i < sz; i++){
                int cur = abs(nums[i]);
                 if(cur && cur <= sz and nums[cur-1] > 0) {
                    nums[cur-1] = -nums[cur-1];
                }
            }
        }
        else return 1;
        for(int i = 0; i < sz; i++) if(nums[i] >= 0) return i+1;
        return sz+1;
    }
};



//56. Merge Intervals

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
        set<int> points;
        unordered_map<int, int> mp, isLft, revMp;
        int sz = intervals.size();
        for(int i = 0; i < sz; i++){
            int lft = intervals[i][0], rht = intervals[i][1];
            isLft[lft] = 1;
            points.insert(lft);
            points.insert(rht);
        }
        int k = 0;
        for(int it : points){
            if(isLft.count(it)){ //key hisebe it thakle 1 return korbe
                k += 2;
                mp[it] = k;
            }
            else mp[it] = ++k;
            revMp[k] = it;
        }
        int LIM = 100000;
        int dif[LIM+5];
        memset(dif, 0, sizeof dif);
        for(int i = 0; i < sz; i++){
            int lft = mp[intervals[i][0]], rht = mp[intervals[i][1]];
            dif[lft] += 1;
            dif[rht+1] -= 1;
        }
        for(int i = 1; i <= LIM; i++) dif[i] += dif[i-1];
        vector< vector<int> > res;
        k = 2;
        while(k < LIM){
            while(dif[k] == 0 && k <= LIM) k++;
            int lft = k;
            while(dif[k] && k <= LIM) k++;
            int rht = k-1;
            if(k > LIM) break;
            res.push_back({revMp[lft], revMp[rht]});
        }

        return res;
    }
};



//42. Trapping Rain Water

class Solution {
public:
    int trap(vector<int>& height) {
        deque<int> dq;
        int sz = height.size();
        if(!sz) return 0;
        dq.push_front(height[0]);
        int last = height[0], res = 0;
        for(int i = 1; i < sz; i++){
            int cur = height[i];
            if(cur >= last){
                while(dq.size()){
                    int top = dq.front(); dq.pop_front();
                    res += last - top;
                }
                dq.push_front(cur);
                last = cur;
            }
            else dq.push_front(cur);
        }
        while(dq.size()){
            int last = dq.front(); dq.pop_front();
            while(dq.size()){
                int top = dq.front();
                if(top < last){
                    res += last - top;
                    dq.pop_front();
                }
                else break;
            }
        }
        return res;
    }
};



//136. Single Number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) res ^= nums[i];

        return res;
    }
};



//169. Majority Element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int winner = 0, vote = 0;
        for(int i = 0; i < nums.size(); i++){
            if(vote == 0){
                winner = nums[i];
                vote = 1;
            }
            else if(winner != nums[i]) --vote;
            else ++vote;
        }
        return winner;
    }
};



//128. Longest Consecutive Sequence
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> bucket(nums.begin(), nums.end());
        int mxLen = 0;
        for(int num : bucket){
            if(!bucket.count(num-1)){
                int cur = num;
                while(bucket.count(cur)) cur++;
                mxLen = max(mxLen, cur - num);
            }
        }
        return mxLen;
    }
};



//238. Product of Array Except Self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        if(!sz) return {};
        vector<int> lft(sz), rht(sz), res(sz);
        lft[0] = 1, rht[sz-1] = 1;
        for(int i = 1; i < sz; i++) lft[i] = lft[i-1]*nums[i-1];
        for(int i = sz-2; i >= 0; i--) rht[i] = rht[i+1]*nums[i+1];
        for(int i = 0; i < sz; i++) res[i] = lft[i]*rht[i];
        return res;
    }
};



//283. Move Zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0, r = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                if(r <= i) r = i + 1;
                while(r < nums.size() && nums[r] == 0) r++;
                if(r == nums.size()) break;
                swap(nums[i], nums[r]);
            }
        }
    }
};



//88. Merge Sorted Array
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while(i >= 0 && j >= 0){
            if(nums1[i] >= nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        while(j >= 0){
            nums1[k] = nums2[j];
            k--, j--;
        }
    }
};



//121. Best Time to Buy and Sell Stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n) return 0;
        int rht_to_lft_mx[n];
        memset(rht_to_lft_mx, 0, sizeof rht_to_lft_mx);
        rht_to_lft_mx[n-1] = 0;
        for(int i = n-2; i >= 0; i--) {
            rht_to_lft_mx[i] = max(prices[i+1], rht_to_lft_mx[i+1]);
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            res = max(res, rht_to_lft_mx[i] - prices[i]);
        }
        return res;
    }
};



//121. Best Time to Buy and Sell Stock (Approach 2)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n) return 0;
        int res = 0, mn = prices[0];
        for(int i = 1; i < n; i++){
            res = max(res, prices[i]-mn);
            mn = min(mn, prices[i]);
        }
        return res;
    }
};



//122. Best Time to Buy and Sell Stock II

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, n = prices.size();
        for(int i = 0; i < n; ){
            int mn = prices[i];
            int k = i+1;
            int cur = mn;
            while(k < n && prices[k] >= cur) {
                cur = prices[k];
                k++;
            }
            res += max(0, cur - mn);
            i = k;
        }
        return res;
    }
};



//Meeting Room II

class Solution {
public:
    int minMeetingRooms(vector<Interval> &intervals) {
        int sz = intervals.size();
        set<int> points;
        unordered_map<int, int> mp;
        for(Interval it : intervals){
            int lft = it.start, rht = it.end;
            points.insert(lft);
            points.insert(rht);
        }
        int k = 0;
        for(int it : points){
            mp[it] = k++;
        }
        int LIM = 5000000;
        int dif[LIM+5];
        memset(dif, 0, sizeof dif);
        for(Interval it : intervals){
            int lft = mp[it.start], rht = mp[it.end];
            dif[lft] += 1;
            dif[rht+1] -= 1;
        }
        for(int i = 1; i <= LIM; i++) dif[i] += dif[i-1];
        int res = 0;
        for(int i = 0; i <= LIM; i++) res = max(res, dif[i]);

        return res;
    }
};



//31. Next Permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int lftPos = 0, rhtPos = 0, flag = 0;
        int sz = nums.size();
        for(int i = sz-1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                lftPos = i-1;
                flag = 1;
                break;
            }
        }
        for(int j = sz-1; j >= 0; j--){
            if(nums[lftPos] < nums[j]){
                rhtPos = j;
                break;
            }
        }
        swap(nums[lftPos], nums[rhtPos]);
        if(!flag) lftPos = -1;
        reverse(nums.begin()+lftPos+1, nums.end());
    }
};



//380. Insert Delete GetRandom O(1)

class RandomizedSet {
    unordered_map<long long int, long long int> mp, index;
    long long int MIN = -100000000000;
    long long int k = 0;
public:
    RandomizedSet() {

    }

    bool insert(int val) {
        k = fmax(0, k);
        long long curVal = val*1LL;
        if(!mp.count(curVal) || mp[curVal] == MIN) {
            mp[curVal] = ++k;
            index[k] = curVal;
            return true;
        }
        else return false;
    }

    bool remove(int val) {
        long long curVal = val*1LL;
        if(!mp.count(curVal) || mp[curVal] == MIN) return false;
        else {
            long long int removeIdx = mp[curVal]; // kon index e ache
            mp[curVal] = MIN;
            long long int lastValue = index[k];
            index[removeIdx] = lastValue;
            if(k != removeIdx) mp[lastValue] = removeIdx;
            --k;
            k = fmax(0, k);
            return true;
        }
    }

    int getRandom() {
        k = fmax(1, k);
        long long int ret = 1 + rand()%k;
        return index[ret];
    }
};
