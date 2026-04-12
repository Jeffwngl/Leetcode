class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();

        int res = 0;

        vector<int>freq(26, 0);

        for (int i = 0; i < n; ++i) {
            freq[text[i] - 'a']++;
        }

        int i = 0;
        while (i < n) {
            // find longest curr run
            int j = i;
            while (j < n && text[j] == text[i]) ++j;

            int runLen = j - i;
            // if spare char exists outside of curr run
            if (runLen < freq[text[i] - 'a']) ++runLen;
            res = max(res, runLen);

            // if next run is same char
            if (j + 1 < n && text[j + 1] == text[i]) {
                int k = j + 1;
                while (k < n && text[i] == text[k]) ++k;

                runLen = j - i + k - j - 1; // run without separator
                
                // two cases, aaacaaa -> aaaaaac or aaacaaca -> aaaaaacc
                runLen += runLen < freq[text[i] - 'a'] ? 1 : 0;

                res = max(res, runLen);
            }

            i = j;
        }

        return res;
    }
};
