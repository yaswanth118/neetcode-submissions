class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;

        queue<string> q;
        q.push(beginWord);
        dict.erase(beginWord); // Mark visited

        int steps = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string curr = q.front();
                q.pop();

                if (curr == endWord) return steps;

                for (int i = 0; i < curr.size(); i++) {
                    char orig = curr[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == orig) continue;
                        curr[i] = c;
                        if (dict.find(curr) != dict.end()) {
                            q.push(curr);
                            dict.erase(curr); // Erase immediately to avoid duplicate pushes
                        }
                    }
                    curr[i] = orig;
                }
            }
            steps++;
        }
        return 0;
    }
};