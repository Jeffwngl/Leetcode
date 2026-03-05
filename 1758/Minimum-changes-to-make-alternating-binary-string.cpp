class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if (n == 1) {
            return 0;
        }

        char prevNum = s[0];
        int cnt1 = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == prevNum) {
                if (s[i] == '1') {
                    prevNum = '0';
                }
                else {
                    prevNum = '1';
                }
                cnt1++;
                continue;
            }
            prevNum = s[i];
        }

        int cntNum = 1;
        if (s[0] == '1') {
            prevNum = '0';
        } 
        else {
            prevNum = '1';
        }

        for (int i = 1; i < n; i++) {
            if (s[i] == prevNum) {
                if (s[i] == '1') {
                    prevNum = '0';
                }
                else {
                    prevNum = '1';
                }
                cntNum++;
                continue;
            }
            prevNum = s[i];
        }

        return min(cntNum, cnt1);
    }
};
