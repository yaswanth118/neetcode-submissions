class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& b) {
        int n = 9;
        for (int i = 0; i < 9; i++) {
            set<int> s;
            for (int j = 0; j < 9; j++) {
                if(b[i][j] == '.') continue;
                if (s.find(b[i][j]) == s.end()) {
                    s.insert(b[i][j]);
                } else {
                    cout<< i << ": " << j << endl;
                    return false;
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            set<int> s;
            for (int j = 0; j < 9; j++) {
                if(b[j][i] == '.') continue;
                if (s.find(b[j][i]) == s.end()) {
                    s.insert(b[j][i]);
                } else {
                    cout<< i << " " << j << endl;
                    return false;
                }
            }
        }
        for (int io = 0; io < 3; io++) {
            for (int jo = 0; jo < 3; jo++) {
                set<int> s;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if(b[i + 3 * io][j + 3 * jo] == '.') continue;
                        if (s.find(b[i + 3 * io][j + 3 * jo]) == s.end()) {
                            s.insert(b[i + 3 * io][j + 3 * jo]);
                        } else {
                            cout << i << " " << j << " " << io << " " << jo << endl;
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
