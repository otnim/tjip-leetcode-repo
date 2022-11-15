//TC: O(|s| * |number|)
//MC: O(|s| * |number|)

class Solution {
public:
    int calculate(string s) {
        queue<string> q;
        string str = "";
        for(char ch : s){
            if(ch == ' ') continue;
            if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                q.push(str);
                q.push(string(1, ch));
                str = "";
            }
            else str.push_back(ch);
        }
        q.push(str);

        stack<string> stk;

        while(q.size()){
            string cur = q.front(); q.pop();
            if(cur == "*" || cur == "/"){
                int stkTop = stoi(stk.top()); stk.pop();
                int qFront = stoi(q.front()); q.pop();
                int value = cur == "*" ? (stkTop * qFront) : (stkTop / qFront);
                stk.push(to_string(value));
            }
            else stk.push(cur);
        }

        stack<string> stk2;
        while(stk.size()){
            stk2.push(stk.top()); stk.pop();
        }

        while(stk2.size() > 2){
            int val1 = stoi(stk2.top()); stk2.pop();
            string op = stk2.top(); stk2.pop();
            int val2 = stoi(stk2.top()); stk2.pop();
            int value = op == "+" ? (val1 + val2) : (val1 - val2);
            stk2.push(to_string(value));
        }

        return stoi(stk2.top());
    }
};
