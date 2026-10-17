class Solution {
    // Assumes the LAST element of a is a global max of a.
    int calc(const vector<int>& a) {
        int n = a.size();
        vector<int> pr(n);
        pr[0] = a[0];
        for (int i = 1; i < n; i++) pr[i] = pr[i - 1] + a[i];

        vector<int> nxt(n, -1);
        stack<pair<int, int>> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && s.top().first <= a[i]) {
                nxt[s.top().second] = i;
                s.pop();
            }
            s.push({a[i], i});
        }

        int ans = 0, ctr = 0;
        while (ctr < n) {
            int next = nxt[ctr];
            if (next != -1) {
                ans += a[ctr] * (next - ctr - 1) - (pr[next - 1] - pr[ctr]);
                ctr = next;
            } else {
                ctr++;
            }
        }
        return ans;
    }

   public:
    int trap(vector<int>& h) {
        int gm = max_element(h.begin(), h.end()) - h.begin();
        vector<int> left(h.begin(), h.begin() + gm + 1);
        vector<int> right(h.rbegin(), h.rend() - gm);  // h[n-1] ... h[gm]
        return calc(left) + calc(right);
    }
};