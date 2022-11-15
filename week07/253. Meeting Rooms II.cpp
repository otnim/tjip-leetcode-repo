//TC: O(N), N = 1000005
//MC: O(N)

class Solution{
public:
    int minMeetingRooms(vector<vector<int>>& intervals){
        vector<int> dif(1000005, 0);
        for(auto interval : intervals){
            int st = interval[0], ed = interval[1];
            dif[st]++;
            dif[ed]--;
        }
        int mx = dif[0];
        for(int i = 1; i <= 1000000; i++){
            dif[i] += dif[i-1];
            mx = max(mx, dif[i]);
        }
        return mx;
    }
};
