class Solution {
   public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        vector<int> nxt(n, -1);
        stack<pair<int, int>> s;
        for (int i = 0; i < h.size(); i++) {
            while (!s.empty() && s.top().first >= h[i]) {
                pair<int, int> cur = s.top();
                s.pop();
                nxt[cur.second] = i;
            }
            s.push({h[i], i});
        }

        int l = 0, r = n-1;
        int ans = 0;
        while(l < r) {
            ans = max(ans, (r-l)*(min(h[r], h[l])));
            if(h[l] < h[r]){
                l++;
            } else {
                r--;                
            }
        }
        return ans;
    }
};
