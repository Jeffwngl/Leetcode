#include <algorithm>
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if (n == 1) {
            return 0;
        }
        
        vector<int>v;
        v.resize(n);
        for (int i = 0; i < n; ++i) {
            v[i] = static_cast<int>(s[i]);
        }

        if (n == 2) {
            if (v[0] > v[1]) {
                return -1;
            }
            return 0;
        }

        vector<int> v_sorted = v;
        
        vector<int> r_sorted = v;
        vector<int> l_sorted = v;

        sort(v_sorted.begin(), v_sorted.end());

        sort(r_sorted.begin() + 1, r_sorted.end());
        sort(l_sorted.begin(), l_sorted.end() - 1);

        if (is_sorted(v.begin(), v.end())) {
            return 0;
        }

        if (v_sorted == r_sorted || v_sorted == l_sorted) {
            return 1;
        }

        vector<int>a = v;
        vector<int>b = v;

        sort(a.begin(), a.end() - 1);
        sort(a.begin() + 1, a.end());

        sort(b.begin() + 1, b.end());
        sort(b.begin(), b.end() - 1);

        if (a == v_sorted || b == v_sorted) {return 2;}
        return 3;
    }
};
