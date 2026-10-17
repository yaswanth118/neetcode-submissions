class Solution {
   public:
    int maxProfit(vector<int>& a) {
        int n = a.size();

        vector<int> nxt(n, -1);
        vector<int> vis(n, -1);
        stack<pair<int, int>> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && s.top().first <= a[i]) {
                nxt[s.top().second] = i;
                s.pop();
            }
            s.push({a[i], i});
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int ctr = i;
            while(nxt[ctr] != -1) {
                vis[ctr]= 1;
                ctr = nxt[ctr];
            }
            ans = max(ans, a[ctr] - a[i]);
        }
        return ans;
    }
};
