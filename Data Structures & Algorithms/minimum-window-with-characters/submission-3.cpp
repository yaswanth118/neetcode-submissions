class Solution {
   public:
    string minWindow(string s, string t) {
        map<char, int> mpt;
        for (auto c : t) {
            mpt[c]++;
        }
        map<char, int> mps;
        // for (int i = 0; i < t.size(); i++) {
        //     mps[s[i]]++;
        // }

        pair<int, int> ans;
        int val = INT_MAX;
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            
            mps[s[r]]++;
            bool ok = true;
            for (auto x : mpt) {
                if (mps[x.first] < x.second) {
                    ok = false;
                }
            }
            // cout<<ok<<" "<<r<<endl;
            while (ok && mps[s[l]] - 1 >= mpt[s[l]]) {
                // cout<<l << " " << mps[]
                mps[s[l]]--;
                l++;
            }
            if (ok == true) {
                if (val > r - l + 1) {
                    // cout << l << " " << r << endl;
                    val = r - l + 1;
                    ans = {l, r};
                }
            }
        }
        string ret = "";
        if (val == INT_MAX) {
            return ret;
        }
        for (int i = ans.first; i <= ans.second; i++) {
            ret.push_back(s[i]);
        }
        return ret;
    }
};
