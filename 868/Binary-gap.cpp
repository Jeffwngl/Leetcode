class Solution {
public:
    int binaryGap(int n) {
        if (n == 1) {
            return 0;
        }
        string a = bitset<sizeof(int) * 8>(n).to_string();
        int maxCnt = 0;
        int curr = 0;
        cout << a << endl;
        char k = a[0];
        while (k != '1') {
            if (!a.empty()) {
                a.erase(0, 1);
            }
            k = a[0];
        }

        for (int i = 0; i < a.size(); i++) {
            if (a[i] == '1') {
                if (curr > 0) {
                    maxCnt = max(maxCnt, curr);
                    curr = 0;
                    // continue;
                }
            }
            curr++;
        }
        if (a[a.size() - 1] == '1') {
            maxCnt = max(maxCnt, curr);
        }

        return maxCnt;
    }
};
