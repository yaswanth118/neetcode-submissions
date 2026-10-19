class Solution {
   public:
    int numIslands(vector<vector<char>>& g) {
        vector<vector<int>> vis((int)g.size(), vector<int>((int)g[0].size(), 0));
        int n = g.size();
        int m = g[0].size();
        int cc = 0;
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[i].size(); j++) {
                if (vis[i][j] == 0 && g[i][j] == '1') {
                    cc++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        int dx[4] = {1, 0, 0, -1};
                        int dy[4] = {0, 1, -1, 0};
                        for (int k = 0; k < 4; k++) {
                            if (p.first + dx[k] >= 0 && p.first + dx[k] < n && p.second + dy[k] >= 0 &&
                                p.second + dy[k] < m && g[p.first + dx[k]][p.second + dy[k]] == '1' &&
                                vis[p.first + dx[k]][p.second + dy[k]] == 0) {
                                q.push({p.first + dx[k], p.second + dy[k]});
                                vis[p.first + dx[k]][p.second + dy[k]] = 1;
                            }
                        }
                    }
                }
            }
        }
        return cc;
    }
};
