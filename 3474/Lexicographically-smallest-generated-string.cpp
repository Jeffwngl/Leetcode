class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<char>res(n + m - 1, '0');

        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'T') {
                if (res[i] != '0' && res[i] != str2[0]) return "";
                for (int j = i; j < m + i; ++j) {
                    res[j] = str2[j - i];
                }
            }
        }
        // check for invalid cases after placing down all T substrings
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'T') {
                for (int j = i; j < m + i; ++j) {
                    if (res[j] != str2[j - i]) {
                        return "";
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'F') {
                string substring(res.begin() + i, res.begin() + i + m);
                // cout << substring << endl;
                for (auto& c : substring) if (c == '0') c = 'a';
                if (substring == str2) {
                    for (int j = m + i - 1; j >= i; --j) {
                        if (res[j] == '0' && substring[j - i] == 'a') {
                            res[j] = 'b';
                            break;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'F') {
                string substring(res.begin() + i, res.begin() + i + m);
                if (substring == str2) return "";
            }  
        }

        for (int i = 0; i < res.size(); ++i) {
            if (res[i] == '0') res[i] = 'a';
        }

        string s(res.begin(), res.end());
        return s;
    }
};
