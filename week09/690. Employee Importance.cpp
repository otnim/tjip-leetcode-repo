//TC: O(N)
//MC: O(N + H)

class Solution {
public:
    unordered_map<int, int> totalImportance;
    unordered_map<int, int> idPos;
    vector<vector<int>> adj;


    int calImportance(int u, vector<Employee*>& employees){
        if(adj[u].size() == 0) {
            return employees[idPos[u]]->importance;
        }

        int total = employees[idPos[u]]->importance;
        for(int v : adj[u]){
            total += calImportance(v, employees);
        }
        return total;
    }

    int getImportance(vector<Employee*> employees, int id) {
        adj.resize(2005);
        int k = 0;
        for(auto it : employees){
            int ID = it->id;
            if(!idPos.count(ID)) idPos[ID] = k++;
            for(auto u : it->subordinates){
                adj[ID].push_back(u);
            }
        }

        return calImportance(id, employees);
    }
};



/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

