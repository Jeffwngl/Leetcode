class Solution {
public:
    int almostPalindromic(string s) {
        int n = s.size();

        int res = 0;

        for (int i = 0; i < n; i++) {
            int l = i;
            int r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                res = max(res, r - l + 2);
                l--;
                r++;
            }
            int l2 = l - 1;
            int r2 = r;
            while (l2 >= 0 && r2 < n && s[l2] == s[r2]) {
                res = max(res, r2 - l2 + 1);
                l2--;
                r2++;
            }
            l2 = l;
            r2 = r + 1;
            while (l2 >= 0 && r2 < n && s[l2] == s[r2]) {
                res = max(res, r2 - l2 + 1);
                l2--;
                r2++;
            }
        }

        for (int i = 0; i < n; i++) {
            int l = i; 
            int r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                res = max(res, r - l + 2);
                l--;
                r++;
            }
            int l2 = l - 1;
            int r2 = r;
            while (l2 >= 0 && r2 < n && s[l2] == s[r2]) {
                res = max(res, r2 - l2 + 1);
                l2--;
                r2++;
            }
            l2 = l;
            r2 = r + 1;
            while (l2 >= 0 && r2 < n && s[l2] == s[r2]) {
                res = max(res, r2 - l2 + 1);
                l2--;
                r2++;
            }
        }
        return min(n, res); // prevent overcounting from first for loop + 2 statement
    }
};
