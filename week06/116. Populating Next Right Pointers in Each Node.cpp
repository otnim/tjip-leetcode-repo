//TC: O(N)
//MC: O(N)

class Solution {
public:
    Node* connect(Node* root) {
        while(!root) return root;

        queue<Node*> q; q.push(root);

        while(q.size()){
            int length = q.size();
            for(int i = 1; i <= length; i++){
                Node* u = q.front(); q.pop();
                if(i < length) u->next = q.front();

                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
        }
        return root;
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
