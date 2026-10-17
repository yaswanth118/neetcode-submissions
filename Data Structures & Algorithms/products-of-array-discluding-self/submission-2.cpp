class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& v) {
        int n = v.size();
        vector<int> p(n), s(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                p[0] = v[0];
            } else {
                p[i] = p[i - 1] * v[i];
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                s[n-1] = v[n-1];
            } else {
                s[i] = s[i + 1] * v[i];
            }
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = (i == 0 ? 1 : p[i - 1]) * (i == n - 1 ? 1 : s[i + 1]);
        }
        return ans;
    }
};
