class Solution {
   public:
    string encode(vector<string>& s) {
        string ans = "";
        for (auto x : s) {
            ans.append((to_string(x.size()) + "#" + x));
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int cnt = 0;
        while (cnt < s.size()) {
            string sz = "";
            while (s[cnt] != '#') {
                sz.push_back(s[cnt]);
                cnt++;
            }
            int len = stoi(sz);
            string t = "";
            cnt++;
            for (int i = 0; i < len; i++) {
                t.push_back(s[cnt]);
                cnt++;
            }
            // cnt += (len + 1);
            ans.push_back(t);
        }
        return ans;
    }
};
