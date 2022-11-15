//TC: O(NlogN)
//MC: O(1)

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        for(int i = 0; i < intervals.size(); i++){
            swap(intervals[i][0], intervals[i][1]);
        }
        sort(intervals.begin(), intervals.end());

        int nonOverLapped = 0, last = -100000;

        for(auto interval : intervals){
            int start = interval[1], end = interval[0];
            if(start >= last){
                nonOverLapped++;
                last = end;
            }
        }

        return intervals.size() - nonOverLapped;
    }
};
