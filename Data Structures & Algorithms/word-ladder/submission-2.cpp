class Solution {
   public:
    void bfs(int node, vector<int>& vis, vector<vector<int>>& adj, vector<int>& dis) {
        queue<int> q;
        vis[node] = 1;
        dis[node] = 0;
        q.push(node);
        while (!q.empty()) {
            int tp = q.front();
            q.pop();
            for (auto c : adj[tp]) {
                if (vis[c] == 0) {
                    dis[c] = dis[tp] + 1;
                    vis[c] = 1;
                    q.push(c);
                }
            }
        }
    }

    int ladderLength(string b, string e, vector<string>& w) {
        unordered_map<string, int> mp;
        for (int i = 0; i < w.size(); i++) {
            mp[w[i]] = i + 1;
        }
        vector<vector<int>> adj(w.size() + 1);
        for (int i = 0; i < w.size(); i++) {
            for (int j = 0; j < w[i].size(); j++) {
                char x = w[i][j];
                for (int k = 0; k < 26; k++) {
                    if ((char)(k + 'a') != x) {
                        w[i][j] = (char)(k + 'a');
                        if (mp.find(w[i]) != mp.end()) {
                            adj[i + 1].push_back(mp[w[i]]);
                            adj[mp[w[i]]].push_back(i + 1);
                        }
                    }
                }
                w[i][j] = x;
            }
        }

        for (int j = 0; j < b.size(); j++) {
            char x = b[j];
            for (int k = 0; k < 26; k++) {
                if ((char)(k + 'a') != x) {
                    b[j] = (char)(k + 'a');
                    if (mp.find(b) != mp.end()) {
                        // adj[mp[b]].push_back(0);
                        adj[0].push_back(mp[b]);
                    }
                }
            }
            b[j] = x;
        }

        vector<int> vis(w.size() + 1, 0);
        vector<int> dis(w.size() + 1, -1);
        bfs(0, vis, adj, dis);

        if (mp.find(e) == mp.end()) {
            return 0;
        }
        return dis[mp[e]] == -1 ? 0 : dis[mp[e]] + 1;
    }
};
