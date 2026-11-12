class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] =1;
        for(auto c: adj[node]) {
            if(vis[c] == 0) {
                dfs(c, adj, vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ctr = 0;
        for(int i=0;i<n;i++){
            if(vis[i] == 0) {
                ctr++;
                dfs(i, adj, vis);
            }
        }
        return ctr;
    }
};
