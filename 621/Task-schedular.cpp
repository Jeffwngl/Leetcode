class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int k = tasks.size();
        vector<int>cnts(26);
        int res = 0;

        // Freq of each letter
        for (int i = 0; i < k; ++i) ++cnts[tasks[i] - 'A'];

        auto mx = *max_element(cnts.begin(), cnts.end());
        int no_mx = 0;
        for (int j = 0; j < 26; ++j) {
            if (cnts[j] == mx) ++no_mx;
        }

        int l = (mx - 1) * (n + 1) + no_mx;

        res = max(l, k);

        return res;
    }
};
