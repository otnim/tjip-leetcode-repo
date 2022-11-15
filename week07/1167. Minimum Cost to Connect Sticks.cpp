//TC: O(NlogN)
//MC: O(N)

class Solution {
public:
    int minimumCost(vector<int> &sticks) {
        priority_queue<int> pq;
        for(int len : sticks){
            pq.push(-len);
        }
        int minCost = 0;
        while(pq.size() > 1){
            int top1 = -pq.top(); pq.pop();
            int top2 = -pq.top(); pq.pop();
            minCost += top1 + top2;
            pq.push(-(top1 + top2));
        }
        return minCost;
    }
};
