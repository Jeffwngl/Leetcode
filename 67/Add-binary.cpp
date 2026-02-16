class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();
        int l = 0;
        if (n > m) {
            for (int i = 0; i < n - m; i++) {
                b = '0' + b;
            }
            l = n;
        }
        else {
            for (int i = 0; i < m - n; i++) {
                a = '0' + a;
            }
            l = m;
        }

        string s;
        int carry = 0;
        for (int i = l - 1; i >= 0; i--) {
            if (a[i] == '1' && b[i] == '1') {
                s = to_string(0 + carry) + s;
                carry = 1;
                continue;
            }
            else if (a[i] == '1' || b[i] == '1') {
                cout << i << endl;
                if (carry > 0) {
                    s = '0' + s;
                    continue;
                }
                else {
                    s = '1' + s;
                    continue;
                }
            }
            else {
                if (carry > 0) {
                    s = '1' + s;
                    carry = 0;
                    continue;
                }
                else {
                    s = '0' + s;
                    continue;
                }
            }
        }
        if (carry > 0) {
            s = "1" + s;
        }
        return s;
    }
};
