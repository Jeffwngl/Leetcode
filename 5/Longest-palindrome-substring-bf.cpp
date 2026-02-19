class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        if (n == 0) {
            return "";
        }
        else if (n == 1) {
            return s;
        }

        string res = "";

        string curr;

        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                curr = s[n - 1];
                continue;
            }

            int l = i, r = i;
            curr = s[i];
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (l == r) {
                    l--;
                    r++;
                    continue;
                }
                curr = s[l] + curr + s[r];
                l--;
                r++;
            }
            res = res.size() < curr.size() ? curr : res;
            cout << "first" << curr << endl;

            l = i;
            r = i + 1;
            curr = "";
            while (l >= 0 && r < n && s[l] == s[r]) {
                curr = s[l] + curr + s[r];
                l--;
                r++;
            }
            res = res.size() < curr.size() ? curr : res;
            cout << "second" << curr << endl;
        }
        res = res.size() < curr.size() ? curr : res;
        return res;
    }
};
