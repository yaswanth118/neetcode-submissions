class Solution {
   public:
    int largestRectangleArea(vector<int>& h) {
        stack<pair<int, int>> s;
        int n = h.size();
        vector<int> nxt(n, n);
        vector<int> prev(n, -1);
        for (int i = 0; i < h.size(); i++) {
            if (s.empty()) {
                s.push({h[i], i});
            } else {
                while (!s.empty() && s.top().first > h[i]) {
                    pair<int, int> p = s.top();
                    s.pop();
                    nxt[p.second] = i;
                }
                s.push({h[i], i});
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (s.empty()) {
                s.push({h[i], i});
            } else {
                while (!s.empty() && s.top().first > h[i]) {
                    pair<int, int> p = s.top();
                    s.pop();
                    prev[p.second] = i;
                }
                s.push({h[i], i});
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, h[i] * (nxt[i] - prev[i] - 1));
        }
        return ans;
    }
};
