class Solution {
   public:
    void pacific(vector<vector<int>>& v, int n, int m, queue<pair<int, int>>& q,
                 vector<vector<int>>& r) {
        // vector<vector<int>> r;
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int dx[4] = {0, 0, 1, -1};
            int dy[4] = {1, -1, 0, 0};
            for (int i = 0; i < 4; i++) {
                if (p.first + dx[i] >= 0 && p.first + dx[i] < n && p.second + dy[i] >= 0 &&
                    p.second + dy[i] < m) {
                    if (v[p.first + dx[i]][p.second + dy[i]] >= v[p.first][p.second] &&
                        r[p.first + dx[i]][p.second + dy[i]] == 0) {
                        r[p.first + dx[i]][p.second + dy[i]] = 1;
                        q.push({p.first + dx[i], p.second + dy[i]});
                    }
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        queue<pair<int, int>> q1;
        vector<vector<int>> r1(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            q1.push({i, 0});
            r1[i][0] = 1;
        }
        for (int i = 0; i < m; i++) {
            q1.push({0, i});
            r1[0][i] = 1;
        }

        queue<pair<int, int>> q2;
        vector<vector<int>> r2(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            q2.push({i, m - 1});
            r2[i][m - 1] = 1;
        }
        for (int i = 0; i < m; i++) {
            q2.push({n - 1, i});
            r2[n - 1][i] = 1;
        }

        pacific(v, n, m, q1, r1);
        pacific(v, n, m, q2, r2);
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (r1[i][j] == 1 && r2[i][j] == 1) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
