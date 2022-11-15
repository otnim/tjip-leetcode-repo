//TC: O(N)
//MC: O(N)

class Solution {
public:
    vector<vector<int>> adj;

    bool hasCycle(int u, vector<int>& vis){
        vis[u] = 1;

        bool status = false;

        for(int v : adj[u]){
            if(vis[v] == 1) status = 1;
            else if(!vis[v]) status |= hasCycle(v, vis);
        }

        vis[u] = 2;
        return status;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses + 1);

        bool isCyclic = 0;
        vector<int> inDegree(numCourses, 0);
        vector<int> vis(numCourses, 0);

        for(auto pre : prerequisites){
            if(pre[0] == pre[1]) isCyclic = 1;
            inDegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> indCourses;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
               indCourses.push_back(i);
            }
        }

        for(int i = 0; i < indCourses.size(); i++){
            if(inDegree[indCourses[i]] == 0) isCyclic |= hasCycle(indCourses[i], vis);
        }
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]) isCyclic = 1;
        }


        return !isCyclic;
    }
};
