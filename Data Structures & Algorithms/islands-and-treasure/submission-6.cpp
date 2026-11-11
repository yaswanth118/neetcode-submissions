#define INF 2147483647

class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& v) {
        queue<pair<int, int>> q;
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> dis(v.size(), vector<int>(v[0].size(), INF));
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[0].size(); j++) {
                if (v[i][j] == 0) {
                    q.push({i, j});
                    dis[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> p = q.front();
            cout<<p.first << " "<<p.second << endl;
            q.pop();
            vector<int> dx = {0, 0, 1, -1};
            vector<int> dy = {1, -1, 0, 0};
            for (int i = 0; i < 4; i++) {
                if (p.first + dx[i] >= 0 && p.first + dx[i] < n && p.second + dy[i] >= 0 &&
                    p.second + dy[i] < m) {
                    if (v[p.first + dx[i]][p.second + dy[i]] == INF &&
                        dis[p.first + dx[i]][p.second + dy[i]] == INF) {
                        q.push({p.first + dx[i], p.second + dy[i]});
                        dis[p.first + dx[i]][p.second + dy[i]] = dis[p.first][p.second] + 1;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dis[i][j] != INF) {
                    v[i][j] = dis[i][j];
                }
            }
        }
        
    }
};
