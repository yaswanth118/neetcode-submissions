class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        int n = a.size();

        vector<int> nxt(n, 0);
        stack<pair<int, int>> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && s.top().first < a[i]) {
                nxt[s.top().second] = i;
                s.pop();
            }
            s.push({a[i], i});
        }
        for(int i=0;i<n;i++){
            nxt[i] = (nxt[i] == 0) ? 0 : nxt[i] - i;
        }
        return nxt;


    }
};
