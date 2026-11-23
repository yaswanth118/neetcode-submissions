class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;

        unordered_set<string> head{beginWord}, tail{endWord};
        dict.erase(beginWord);
        dict.erase(endWord);

        int steps = 1;
        while (!head.empty() && !tail.empty()) {
            // Always expand the smaller frontier to minimize branching
            if (head.size() > tail.size()) {
                swap(head, tail);
            }

            unordered_set<string> next_frontier;
            for (string word : head) {
                for (int i = 0; i < word.size(); i++) {
                    char orig = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == orig) continue;
                        word[i] = c;

                        // Frontiers met in the middle
                        if (tail.find(word) != tail.end()) {
                            return steps + 1;
                        }

                        if (dict.find(word) != dict.end()) {
                            next_frontier.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = orig;
                }
            }
            head = move(next_frontier);
            steps++;
        }
        return 0;
    }
};