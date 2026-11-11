/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    void dfs(Node* node, vector<int>& vis, vector<Node*>& vals) {
        vis[node->val] = 1;
        vals[node->val] = node;
        cout << node->val << endl;
        for (Node* c : node->neighbors) {
            if (vis[c->val] == 0) {
                dfs(c, vis, vals);
            }
        }
    }

    void print(Node* node, vector<int>& vis, vector<Node*>& vals) {
        vis[node->val] = 1;
        vals[node->val] = node;
        cout << node->val << endl;
        // for (Node* c : node->neighbors) {
        //     if (vis[c->val] == 0) {
        //         dfs(c, vis, vals);
        //     }
        // }
    }

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        vector<int> vis(101, 0);
        vector<Node*> vals(101);
        dfs(node, vis, vals);
        int n = 0;
        for (int i = 1; i < 101; i++) {
            if (vis[i] == 1) {
                n = i ;
            }
        }
        vector<Node*> clones(101);
        for (int i = 1; i <= n; i++) {
            clones[i] = new Node(i);
        }

        for (int i = 1; i <= n; i++) {
            for (Node* c : vals[i]->neighbors) {
                clones[i]->neighbors.push_back(clones[c->val]);
            }
        }

        // // vis.clear();
        // vector<int> visb(101, 0);
        // vector<Node*> valsb(101);

        // print(clones[1], visb, valsb);

        return clones[1];
        // return new Node(1);
    }
};
