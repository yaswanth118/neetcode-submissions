class Solution {
   public:
    bool canFinish(int n, vector<vector<int>>& p) {
        // 0..n-1  are the nodes.
        vector<int> in(n, 0);
        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < p.size(); i++) {
            adj[p[i][1]].push_back(p[i][0]);
            in[p[i][0]]++;
        }
        queue<int> q;
        int vc = 0;
        for (int i = 0; i < n; i++) {
            if(in[i] == 0) {
                q.push(i);
                vc++;
            }
        }
        
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            for(auto c: adj[t]) {
                in[c]--;
                if(in[c] == 0) {
                    q.push(c);
                    vc++;
                }
            }
        }
        return vc == n ? true: false;
    }
};
