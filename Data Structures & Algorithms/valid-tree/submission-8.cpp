class Solution {
   public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        bool ans = true;

        for (auto c : adj[node]) {
            if (vis[c] == 1 && c != parent) {
                return false;
            }
            if(vis[c] != 1)
            ans = ans & dfs(c, node, adj, vis);
        }
        return ans;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        bool ans = false;
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        ans = dfs(0, -1, adj, vis);

        if (*min_element(vis.begin(), vis.end()) == 0) {
            return false;
        } else {
            return ans;
        }
    }
};
