//TC: O(N)
//MC: O(H)

class Solution {
public:
    vector<vector<int>> adj;
    int calTime(int u, int prev, vector<int>& manager, vector<int>& informTime){
        int mx = 0;
        for(int v : adj[u]){
            if(v != prev){
                mx = max(mx, informTime[u] + calTime(v, u, manager, informTime));
            }
        }

        return mx;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        adj.resize(n);

        for(int i = 0; i < n; i++){
            if(manager[i] != -1) adj[manager[i]].push_back(i);
        }

        int totalTime = calTime(headID, -1, manager, informTime);

        return totalTime;
    }
};
