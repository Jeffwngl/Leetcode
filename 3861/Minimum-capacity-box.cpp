class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();
        int res = 101;
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (capacity[i] >= itemSize) {
                if (capacity[i] < res) {
                    res = capacity[i];
                    idx = i;
                }
            }
        }
        return idx;
    }
};
