class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        int sz = s1.size();
        if (s1.size() > s2.size()) {
            return false;
        }
        vector<int> golden(26, 0);
        vector<int> c(26, 0);

        for (int i = 0; i < sz; i++) {
            c[s2[i] - 'a']++;
            golden[s1[i] - 'a']++;
        }
        bool possible = true;
        for (int i = 0; i < 26; i++) {
            if (c[i] != golden[i]) {
                possible = false;
            }
        }
        if (possible) {
            return true;
        }

        for (int r = sz; r < n; r++) {
            c[s2[r] - 'a']++;
            c[s2[r - sz] - 'a']--;

            bool possible = true;
            for (int i = 0; i < 26; i++) {
                if (c[i] != golden[i]) {
                    possible = false;
                }
            }
            if (possible) {
                return true;
            }
        }
        return false;
    }
};
