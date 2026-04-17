class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> lookUp(wordList.begin(), wordList.end());
        if (!lookUp.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);

        int changes = 1;

        while (!q.empty()) {
            int sz = q.size();

            for (int k = 0; k < sz; ++k) {
                string curr = q.front();
                q.pop();

                if (curr == endWord) return changes;

                for (int i = 0; i < curr.size(); ++i) {
                    string changed = curr;

                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == curr[i]) continue;

                        changed[i] = c;

                        if (lookUp.count(changed)) {
                            q.push(changed);
                            lookUp.erase(changed); // mark visited
                        }
                    }
                }
            }
            ++changes;
        }

        return 0;
    }
};
